class Solution {
public:
    bool predicate(int mid,vector<int>&nums,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return (cnt>=k);
    }
    int minCapability(vector<int>& nums, int k) {
        int low=0,high=*max_element(nums.begin(),nums.end()),mid,ans=0;
        while(low<=high){
         mid=(low+high)/2;
         if(predicate(mid,nums,k)){
            ans=mid;
            high=mid-1;
         }
         else{
            low=mid+1;
         }
        }
        return ans;
    }
};