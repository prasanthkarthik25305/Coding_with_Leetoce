class Solution {
public:
vector<vector<int>>dp;
    int rec(vector<vector<int>>& obstacleGrid,int row,int col,int n,int m){
         if(row>=n) {
            return 0;
        }
        if(col>=m) {
           return 0;
        }
        if(obstacleGrid[row][col]==1) return 0;
         if(row==n-1 and col==m-1){
            return 1;
        }
        if(dp[row][col]!=-1){
          return dp[row][col];
        }
        int a=0,b=0;
        a=rec(obstacleGrid,row,col+1,n,m);
        b=rec(obstacleGrid,row+1,col,n,m);
        return dp[row][col] = (a+b);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
       dp.resize(n,vector<int>(m,-1));
       int ans=rec(obstacleGrid,0,0,n,m);
        return ans;
    }
};