class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<pair<int,int>>ans(mat.size()*mat[0].size()+1);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                ans[mat[i][j]] = {i,j};
            }
        }
        //int row=0,col=0;
        vector<int>row(mat.size()+1,0),col(mat[0].size()+1,0);
        for(int i=0;i<arr.size();i++){
             row[ans[arr[i]].first]++;
             col[ans[arr[i]].second]++;
             if(row[ans[arr[i]].first]==mat[0].size()) return i;
             if(col[ans[arr[i]].second]==mat.size()) return i;
        }
       
      return 0;
    }
};