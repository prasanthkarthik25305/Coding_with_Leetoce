class Solution {
public:
    vector<int>que;
    
    //check 
    bool check(int row,int col){
        for(int i=0;i<row;i++){
            int pcol=que[i];
            int prow=i;
            if(col==pcol||abs(row-prow)==abs(col-pcol)) return false;

        }
        return true;
    }
    int rec(int row,int n){
        if(row==n){
            return 1;
        }
        int ans=0;
        for(int col=0;col<n;col++){
            if(check(row,col)){
                que[row]=col;
                ans+=rec(row+1,n);
                que[row]=-1;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
         que = vector<int>(n, -1);
        return rec(0,n);
    }
};