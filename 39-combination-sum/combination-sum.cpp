class Solution {
public:

vector<vector<int>>answer;
    void rec(int ind,vector<int>&candidates,int tar,int sum,vector<int>&curr){
        //pruning
        if(sum>tar || ind>candidates.size()-1) return;
        //basecase
        if(sum==tar){
            answer.push_back(curr);
            return;
        }
     
       rec(ind+1,candidates,tar,sum,curr);
       curr.push_back(candidates[ind]);
       rec(ind,candidates,tar,sum+candidates[ind],curr);
       curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>curr;
        rec(0,candidates,target,0,curr);
        vector<vector<int>>res;
        for(auto i:answer){
            res.push_back(i);
        }
        return res;
    }
};