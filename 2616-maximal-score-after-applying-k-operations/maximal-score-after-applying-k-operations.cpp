class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto i:nums) q.push(i);
        long long score=0,val=0;
        while(!q.empty() and k){
            score+=q.top();
            val=ceil(q.top()*1.0/3);
            q.pop();
            q.push(val);
            k--;
        }
        return score;
    }
};