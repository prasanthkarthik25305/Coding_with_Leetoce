class Solution {
public:
  int mod=1e9+7;
    bool isValidTransform(vector<int>&a,vector<int>&b){
         for(int i=0;i<a.size();i++){
            if(a[i]==b[i]) return false;
         }
         return true;
    }
    void generatestates(int m,int col,int prevcolor,vector<int>&state,vector<vector<int>>&states){
        //pruning
        if(m==col){
             for(int i=0;i<state.size();i++){
                cout<<state[i]<<' ';
            }
            cout<<'\n';
            states.push_back(state);
            return;
        }
        for(int k=0;k<3;k++){
            if(k!=prevcolor){
                state.push_back(k);
                generatestates(m,col+1,k,state,states);
                state.pop_back();
            }
        }
    }
    int numOfWays(int n) {
        vector<int>state;
        vector<vector<int>>states;
        generatestates(3,0,-1,state,states);
        int sz=states.size();
        vector<vector<int>>compatible(sz);
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(isValidTransform(states[i],states[j])){
                     compatible[i].push_back(j);
                }
            }
        }

        vector<int>dp(sz,1);
        for(int row=1;row<n;row++){
            vector<int>newdp(sz,0);
            for(int i=0;i<sz;i++){
                for(auto j:compatible[i]){
                    newdp[i]=(newdp[i]+dp[j])%mod;
                }
            }
            dp=newdp;
        }

        int ans=0;
        for(auto i:dp){
            ans=(ans+i)%mod;
        }
        return ans;
    }
};