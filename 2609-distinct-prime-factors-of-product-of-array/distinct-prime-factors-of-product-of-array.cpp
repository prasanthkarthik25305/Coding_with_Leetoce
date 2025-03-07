class Solution {
    int n=1e3+1;
    set<int>st;
    vector<int>spf;
void seive(){
    spf.resize(n);
    for(int i=0;i<n;i++){
        spf[i]=i;
    }
 for(int i=2;i*i<=n;i++){
  if(spf[i]==i){
    for(int j=i*i;j<n;j+=i){
        if(spf[j]==j) spf[j]=i;
    }
  }
 }
 //
}
 void no_of_Primefactors(int n){
    while(n>1){
        st.insert(spf[n]);
        n=n/spf[n];
    }
 }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        st.clear();
       seive();
       for(auto i:nums){
        no_of_Primefactors(i);
       } 
       return st.size();
    }
};