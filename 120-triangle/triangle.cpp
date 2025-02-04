class Solution {
public:
   bool col_chk=false;
   //int dp[201][201];
  
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
         vector<int> dp = triangle.back();
         for(int row=n-2;row>=0;row--){
            for(int col=0;col<=row;col++){
                dp[col]=min(dp[col],dp[col+1])+triangle[row][col];
            }
         }
      return dp[0];
    }
};