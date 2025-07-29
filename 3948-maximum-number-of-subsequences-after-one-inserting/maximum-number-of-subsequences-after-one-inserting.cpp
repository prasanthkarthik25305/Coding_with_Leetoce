class Solution {
public:
    #define ll long long 
    ll CntLCTs(string s){
        int n=s.size();
      vector<int>prefix(n+1,0);
      vector<int>suffix(n+1,0);
      for(int i=1;i<n;i++){
        if(s[i-1]=='L') prefix[i+1]=1;
      }
      //for suffix
      for(int i=n-2;i>=0;i--){
        if(s[i+1]=='T') suffix[i+1]=1;
      }
      for(int i=1;i<=n;i++){
           prefix[i]+=prefix[i-1];
      }   
      // for suffix
      for(int i=n-1;i>=1;i--){
        suffix[i]+=suffix[i+1];
      }
     ll ans=0;
     for(int i=0;i<n;i++){
        if(s[i]=='C'){
            ans+=prefix[i+1]*suffix[i+1];
        }
     }
     return ans;
    
    }
    long long numOfSubsequences(string s) {
      string s1="L";
      s1+=s;
      string s2=s;
      s2+="T";
      ll ans1=CntLCTs(s1);
      ll ans2=CntLCTs(s2);

      ll ans3=0;

       int n=s.size();
      vector<int>prefix(n+1,0);
      vector<int>suffix(n+1,0);
      for(int i=0;i<n;i++){
        if(s[i]=='L') prefix[i+1]=1;
      }
      //for suffix
      for(int i=n-1;i>=0;i--){
        if(s[i]=='T') suffix[i+1]=1;
      }
      for(int i=1;i<=n;i++){
           prefix[i]+=prefix[i-1];
      }   
      // for suffix
      for(int i=n-1;i>=1;i--){
        suffix[i]+=suffix[i+1];
      }
      ll maxy=0;
     for(int i=0;i<n;i++){
        if(s[i]!='C'){
            maxy=max(maxy,1LL*prefix[i+1]*suffix[i+1]);
        }
        else ans3+=prefix[i+1]*suffix[i+1];
     }
     ans3+=maxy;
      return max(ans1,max(ans2,ans3));
    }
};