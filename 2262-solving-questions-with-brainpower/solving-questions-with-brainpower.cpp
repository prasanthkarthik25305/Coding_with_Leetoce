class Solution {
public:
vector<long long>dp;
    long long rec(vector<vector<int>>&questions,long long i){
        int n=questions.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long a=0,b=0;
        //pick
        a=questions[i][0];
        if(i+questions[i][1]<n)
        a+=rec(questions,i+questions[i][1]+1);
        //nonpick
        b+=rec(questions,i+1);
        return dp[i]=max(a,b);
    }
    long long mostPoints(vector<vector<int>>& questions) {
       int n=questions.size();
        dp.resize(n,-1);
       return  rec(questions,0);
    }
};