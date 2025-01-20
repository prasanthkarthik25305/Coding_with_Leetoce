class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
         vector<int>res;
        set<pair<int,int>>st;
        for(int i=0;i<k;i++){
            st.insert({nums[i]*-1,i});
        }
        res.push_back((st.begin()->first)*-1);
        cout<<((st.begin()->first)*-1)<<" ";
        for(int i=k;i<n;i++){
            st.erase({nums[i-k]*-1,i-k});
            st.insert({nums[i]*-1,i});
            res.push_back((st.begin()->first)*-1);
        }
        return res;
    }
};