class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxy=INT_MIN,cnt=0;
        for(int left=0,right=0;right<n;right++){
            if(nums[right]==0) cnt++;
            while(cnt>k and left<n){
                if(nums[left]==0) cnt--;
                left++;
            }
            maxy=max(maxy,right-left+1);

        }
        return maxy;
    }
};