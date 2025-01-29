class Solution {
public:
    int rec(vector<vector<int>>&grid,int i,int j,int sum,vector<vector<bool>>&chk){
        int n=grid.size(),m=grid[0].size();
        if(i<0||i>=n||j<0||j>=m|| grid[i][j]==0 || chk[i][j]) return 0;
        chk[i][j]=true;
        sum=grid[i][j];
        cout<<sum<<" ss"<<'\n';
        sum += rec(grid,i+1,j,sum,chk);
        sum += rec(grid,i-1,j,sum,chk);
        sum += rec(grid,i,j+1,sum,chk);
        sum += rec(grid,i,j-1,sum,chk);
        // chk[i][j]=false;
        //sum-=grid
        cout<<sum<<'\n';
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(),maxy=0,sum=0;
        vector<vector<bool>>chk(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxy=max(sum,maxy);  
                if(grid[i][j]!=0) maxy=max(maxy,rec(grid,i,j,0,chk));
                cout<<maxy<<" answer\n";
            }
        } 
        return maxy;
    }
};