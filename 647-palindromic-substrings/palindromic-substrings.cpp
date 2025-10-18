class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }
     int cnt=0;
     for(int i=n-1;i>=0;i--) {
        for(int j=i;j<n;j++) {
            if(i==j){
                dp[i][j]=true;
            }
            else if(j==i+1) {
                dp[i][j]=(s[i]==s[j]);
            }
            else {
                dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
            }
            if(dp[i][j]){
                //cout<<i<<' '<<j<<'\n';
                cnt++;
            }
        }
    }
    return cnt;
        
    }
};