class Solution {
public:
 vector<vector<int>>dp;
   int rec(vector<vector<int>>&grid,int row,int col,int n){
    if(row>=n) return 1e9;
    int m=grid[row].size();
      if (col >= m)  return 1e9;
    if(dp[row][col]!=1e9) return dp[row][col];
    if(row==n-1 and col==m-1) return grid[row][col];
    
    int a=1e9,b=1e9;
   // cout<<"a "<<'\n';
    a=rec(grid,row,col+1,n)+grid[row][col];
    //rec(grid,row+1,col+1,n);
    //cout<<"b "<<'\n';
    b=rec(grid,row+1,col,n)+grid[row][col];
    return dp[row][col]=min(a,b);
   }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),ans=(int)1e9;
        int m=grid[0].size();
        dp.resize(n,vector<int>(m,1e9));
        ans=rec(grid,0,0,n);
    return ans;
    }
};