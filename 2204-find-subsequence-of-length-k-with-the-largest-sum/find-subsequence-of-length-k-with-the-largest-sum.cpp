class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      priority_queue<pair<int,int>>pq1,pq2;
      vector<int>ans;
      for(int i=0;i<nums.size();i++) pq1.push({nums[i],i});
       while(k--){
        pq2.push({pq1.top().second*-1,pq1.top().first});
        pq1.pop();
       }
    while(!pq2.empty()){
        ans.push_back(nums[pq2.top().first*-1]);
        pq2.pop();
    }
    return ans;
    }

};