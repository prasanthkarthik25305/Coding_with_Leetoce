class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
          int n=matrix.size();
        int m=matrix[0].size();
        vector<int>h(m, 0);
        int side,maxarea = 0;
        for(auto &row:matrix){
            for(int i=0;i<row.size();i++){
                h[i]=(row[i]=='1')?h[i]+1:0;
            }
            // for(auto &it : h) cout << it <<" ";
            // cout <<"\n";
            for(int i=0;i<row.size();i++){
                int left=i;
                for(int x=i;x>0 and h[x-1]>=h[i];x--){
                    left--;
                }
                int right=i;
                for(int x=i;x<row.size()-1 and h[x+1]>=h[i];x++){
                    right++;
                }
                 //side=min(h[i],right-left+1);
                 maxarea=max(maxarea,h[i]*(right-left+1));
            }    
        }
         return maxarea;   
    }
};