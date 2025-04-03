class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        //bakward maximum
        vector<int>back(n,0);
        vector<int>forward(n,0);
      back[0]=nums[0];
        for(int i=1;i<n;i++){
            back[i]=max(back[i-1],nums[i]);
        }
       //forward
       forward[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
        forward[i]=max(forward[i+1],nums[i]);
       }
      long long ans=0,maxans=0;
      for(int j=1;j<n-1;j++){
        ans=1ll*(back[j-1]-nums[j])*forward[j+1];
        maxans=max(ans,maxans);
      }
      return maxans;
    }
};