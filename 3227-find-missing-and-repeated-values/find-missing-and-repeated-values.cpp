class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sm=0,n=grid.size();
        n=n*n;
        map<int,int>mp;
        for(auto i:grid){
            for(auto j : i){
                mp[j]++;
                sm += j; 
            }
        }
        vector<int>res;
        for(auto i : mp){
            if(i.second > 1){
                res.push_back(i.first);
            }
        }
        sm-=res[0];
        res.push_back((n*(n+1)/2)-sm);
    return res;
    }
};