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
       set<pair<long long,int>>st;
       for(int i=0,j=0;i<=nums.size();i++){
          while(!st.empty() and prefix[i]-(st.begin()->first)>=k){
            ans=min(ans,i-st.begin()->second);
             cout<< st.begin()->first<<" "<<st.begin()->second<<' '<<i<<'\n';
             st.erase(st.begin());
           
           // cout<<ans;
            //  j++;
          }
          while(!st.empty() and (prefix[i]<=st.rbegin()->first)){
            st.erase(prev(st.end()));
           // cout<<"s"<<' ';
          }
          st.insert({prefix[i],i});
       } 
       return (ans!=nums.size()+1)?ans:-1;
     //  #undef int
    }
};