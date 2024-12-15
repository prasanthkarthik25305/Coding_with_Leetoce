class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        #define int long long
        vector<int>mp(k,1e9);
        int currsum=0,ans=-1e18;
        mp[k-1]=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(i>=k-1){
                ans=max(ans,currsum-mp[i%k]);
              //  cout<<"ans= "<<ans<<" ";
            }
            mp[i%k]=min(mp[i%k],currsum);
            //cout<<"mp= "<<mp[i%k]<<" \n";

        }
        return ans;
        #undef int 
    }
};