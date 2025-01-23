class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       // #define int long long
       int sum=0,ans=nums.size()+1;
       vector<long long>prefix(nums.size()+1,0);
       for(int i=1;i<=nums.size();i++){
       prefix[i]=prefix[i-1]+nums[i-1];
       // else prefix[i]=nums[i];
       }
       deque<int>dq;
       for(int i=0,j=0;i<=nums.size();i++){
          while(!dq.empty() and prefix[i]-prefix[dq.front()]>=k){
           // cout<<dq.front();
            ans=min(ans,i-dq.front());
            dq.pop_front();
             //cout<< st.begin()->first<<" "<<st.begin()->second<<' '<<i<<'\n';
           // cout<<ans;
          }
          while(!dq.empty() and (prefix[i]<prefix[dq.back()])){
           dq.pop_back();
           // cout<<"s"<<' ';
          }
          dq.push_back(i);
       } 
       return (ans!=nums.size()+1)?ans:-1;
     //  #undef int
    }
};