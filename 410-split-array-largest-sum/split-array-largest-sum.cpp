class Solution {
public:
    int splitArray(vector<int>& nums, int k) { 
  int low=-1,n=nums.size();
  long long high=0;
  for(int i=0;i<n;i++){
    low=max(low,nums[i]);
    high+=nums[i];
  }
   #define int long long
  int mid,split=0,sum=0,ans=0;
  while(low<high){
    mid=low+(high-low)/2;
    split=0,sum=0;
    for(auto i:nums){       
      if(sum+i>mid){
        sum=i;
        split++;
      }
      else sum+=i;
    }
    if(split+1>k) low=mid+1;
    else {
        high=mid;
        ans=mid;
    }
    cout<<"low:"<<low<<"mid:"<<mid<<"high:"<<high<<"sum:"<<sum<<'\n';
  }
  return high;
  #undef int   
    }
};