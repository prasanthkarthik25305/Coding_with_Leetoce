
class Solution {
public:
vector<vector<int>>dp;
    int rec(vector<vector<int>>& matrix, int row, int col,int n) {
        if (col < 0 || col >= n)
            return 1e9;
        if (row == n - 1)
            return matrix[row][col];
        if(dp[row][col]!=(int)1e9) return dp[row][col];
        int s1=1e9,s2=1e9,s3=1e9;
       // cout<<"s1 "<<'\n';
         s1= rec(matrix, row + 1, col, n) + matrix[row][col];
       //  cout<<"s2 "<<'\n';
         s2 = rec(matrix, row + 1, col + 1, n) + matrix[row][col];
        // cout<<"s3 "<<'\n';
         s3 = rec(matrix, row + 1, col - 1, n) + matrix[row][col];
        int ans = min(s1, min(s2, s3));
        return dp[row][col]=ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();

       dp.resize(n,vector<int>(m ,1e9));
            for(int j=0;j<matrix[0].size();j++){
             ans=min(ans,rec(matrix,0,j,matrix.size()));
             cout<<ans<<'\n';
            }
        return ans;
    }

};