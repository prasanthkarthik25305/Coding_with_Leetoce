class Solution {
public:
    vector<vector<string>>ans;
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
    void rec(int row,int n,vector<string>sol){
        if(row==n){
            ans.push_back(sol);
            return;
        }
        for(int col=0;col<n;col++){
            if(check(row,col)){
                que[row]=col;
                sol[row][col]='Q';
                rec(row+1,n,sol);
                 sol[row][col]='.';
                que[row]=-1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
         que = vector<int>(n, -1);
        vector<string>sol(n,string(n,'.'));
        rec(0,n,sol);
        return ans;
    }
};