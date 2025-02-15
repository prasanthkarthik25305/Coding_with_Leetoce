class Solution {
public:
     bool punishment(string chkstr,int i,int sum,int target,vector<vector<int>>&dp){
        if(sum>target) return false;
        if(i==chkstr.size()) {
            if(sum==target) return true;
            return false;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
bool chk=false;
        for(int j=i;j<chkstr.size();j++){
            string subchk=chkstr.substr(i,j-i+1);
            int added=stoi(subchk);
            chk=chk||punishment(chkstr,j+1,sum+added,target,dp);
            if(chk==true) return true;
        }
        return dp[i][sum]=chk;
     }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            string ans=to_string(i*i);
            vector<vector<int>>dp(ans.size(),vector<int>(i+1,-1));
            sum+=(punishment(ans,0,0,i,dp))?i*i:0;
        }
        return sum;
    }
};