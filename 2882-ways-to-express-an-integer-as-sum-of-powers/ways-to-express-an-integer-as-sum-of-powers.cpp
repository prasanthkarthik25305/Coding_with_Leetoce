class Solution {
public:
    const int mod =1e9+7;
    int dp[301][301];
    int rec(int n,int x,int sum,int tar) {
        if(sum==tar) return 1;
        if(sum>tar|| n>tar) return 0;
        if(sum>=0 and dp[n][sum]!=-1) return dp[n][sum];
       long long  res1=0,res2=0,add=1,val=0;
      for(int i=1;i<=x;i++){
        add=(add*n)%mod;
      }
     // cout<<add<<'\n';
        val= (sum+add)%mod;
        // cout<<sum<<'\n';
        res1=(res1+rec(n+1,x,val,tar))%mod;
       // cout<<sum<<'\n';
        res2=(res2+rec(n+1,x,sum,tar))%mod;
        
        return dp[n][sum]=(res1+res2)%mod;
    }
    int numberOfWays(int n, int x) {
    memset(dp,-1,sizeof(dp));

     int ans=  rec(1,x,0,n);
    // cout<<"First"<<'\n';
    // for(auto i=0;i<=n;i++){
    //     cout<<dp[i][x]<<'\n';
    // }

    return ans;
    }
};