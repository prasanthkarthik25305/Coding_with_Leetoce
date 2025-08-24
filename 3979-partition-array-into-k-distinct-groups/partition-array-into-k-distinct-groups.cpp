class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        map<int,int>mp;
        
        if(n%k!=0) return false;
        for(auto i:nums) mp[i]++;
        for(auto i:mp){
            if(i.second>n/k) return false;
        }
        return true;
    }
};