class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int>maxdq,mindq;
      long long l=0,cnt=0;
        for(int r=0;r<nums.size();r++){
            while(!maxdq.empty() and maxdq.back()<nums[r]){
                maxdq.pop_back();
            }
            maxdq.push_back(nums[r]);

             while(!mindq.empty() and mindq.back()>nums[r]){
                mindq.pop_back();
            }
            mindq.push_back(nums[r]);

            while(!maxdq.empty() && !mindq.empty() && maxdq.front()-mindq.front()>=3){
                if(mindq.front()==nums[l]) mindq.pop_front();
                if(maxdq.front()==nums[l]) maxdq.pop_front();
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};