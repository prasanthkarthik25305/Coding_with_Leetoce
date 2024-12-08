class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      map<int,int>mp;
      for(auto i:nums){
        mp[i]++;
      }  
      int cnt=0;
      for(auto i:mp){
        if(k<i.first) cnt++;
        else if(k>i.first) return -1;
      }
      return cnt;
    }
};