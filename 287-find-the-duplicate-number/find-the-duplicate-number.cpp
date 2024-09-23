class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
       bool a[100100]={false};
       for(int i=0;i<nums.size();i++){
        if(a[nums[i]]!=true){
            a[nums[i]]=true;
        }
      else{
        return nums[i];
      }
       } 
       return 0;
    }
};