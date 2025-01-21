class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
       vector<double>ans;
        multiset<long long>lo,hi;
         auto balance=[&]{
            if(lo.size()>hi.size()+1){
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            else if(hi.size()>lo.size()){
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };
        for(int i=0;i<nums.size();i++){
            if(lo.empty()||nums[i]<=*lo.rbegin()) lo.insert(nums[i]);
            else hi.insert(nums[i]);
        balance();
        //deletions
        if(i>=k){
            int value=nums[i-k];
            if(*lo.rbegin()>=value) lo.erase(lo.find(value));
            else hi.erase(hi.find(value));
        }
        balance();
        //
        double mid;
        if(i>=k-1){
            if(k%2==1) mid=*lo.rbegin();
            if(k%2==0) mid=(((*lo.rbegin())+(*hi.begin()))/2.0);
            ans.emplace_back(mid); 
        }
        }
        return ans;
    }
};