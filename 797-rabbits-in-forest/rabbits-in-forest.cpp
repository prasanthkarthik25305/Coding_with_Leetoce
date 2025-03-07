class Solution {
public:
    int numRabbits(vector<int>& answers) {
    map<int,int>mp;int cnt=0;
    for(auto i:answers) mp[i]++;
    for(auto i:mp){
      cnt+=ceil(1.0*(mp[i.first])/(i.first+1))*(i.first+1);
    }
     return cnt;   
    }
};