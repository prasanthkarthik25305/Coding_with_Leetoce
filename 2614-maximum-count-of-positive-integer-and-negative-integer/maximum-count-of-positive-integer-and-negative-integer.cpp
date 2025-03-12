class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n, mid, posindex=n;
        //first postive
        while (low< high) {
            mid = (low + high) / 2;
            if (nums[mid] > 0) {
                posindex = mid;
                high = mid;
            } else {
                low = mid+1;
            }
        }

      //finding last negative
      low=0,high=n,mid;
      int negindex=0;
     while(low<high){
        mid=(low+high)/2;
        if(nums[mid]<0){
            negindex=mid+1;
            low=mid+1;
        }
        else high=mid;
     }
      return max(negindex,n-posindex);
        // int cnt1=0,cnt2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]<0) cnt1++;
        //     else cnt2++;
        // }
        // return min(cnt1,cnt2);
    }
};