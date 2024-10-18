class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxy=0,cnt=0,curr;
        for(auto i:nums) maxy|=i;
        
        for(int i=0;i<(1<<nums.size());i++){
             curr=0;
            for(int j=0;j<nums.size();j++){
                if(((i>>j)&1)==1) curr|=nums[j];
            }
            if(curr==maxy)cnt++;
        }
        return cnt;
    }
};