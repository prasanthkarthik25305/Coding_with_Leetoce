class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     int maxy=INT_MIN,maxlen=INT_MIN,len=0;
     for(auto i:nums) maxy=max(maxy,i);
     for(int i=0;i<nums.size();i++){
        if(nums[i]==maxy ){
            len++;
        }
        else{
            len=0;
        }
        maxlen=max(maxlen,len);
     }  
     return maxlen;
    }
};