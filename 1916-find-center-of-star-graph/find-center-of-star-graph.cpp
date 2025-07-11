class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        int cnt=0,ans=0;
        for(int i=0;i<2;i++){
          mp[edges[i][0]]++;
          mp[edges[i][1]]++;
        }
        for(auto i:mp){
            if(i.second>cnt){
                ans=i.first;
                cnt=i.second;
            }
        }
        return ans;


    }
};