class Solution {
public:
    bool canJump(vector<int>& nums) {
        int chk=0;
        for(int i=0;i<nums.size();i++){
            if(chk<i) return false;
               chk=max(chk,nums[i]+i);
        }
        return true;
    }
};