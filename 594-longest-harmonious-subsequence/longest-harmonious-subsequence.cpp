class Solution {
public:
    int findLHS(vector<int>& nums) {
//   1 2 2 2 3 3 5 7

      sort(nums.begin(),nums.end());
      int n=nums.size();
      if(n==1) return 0;
      int i=0,j=1;
      int size=0;
      while(i<n and j<n){
          while(j<n and nums[j]-nums[i]<=1){
          if(nums[j]-nums[i]==1) size=max(size,j-i+1);
            j++;
          }
          i++;
      }
// 1 1 2 2
      return size;
    }
};