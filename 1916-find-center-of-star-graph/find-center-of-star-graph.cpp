class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        for(auto edge:edges) {
            mp[edge[0]]++;
            mp[edge[1]]++;
        }

        int maxy=0,ans=0;
        for(auto i:mp){
            if(i.second>maxy){
             ans=i.first;
             maxy=i.second;
            }
        }
        return ans;
    }
};