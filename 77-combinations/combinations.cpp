class Solution {
public:
    vector<vector<int>> ans;
    void rec(int n, int k, vector<int>& res, int ind) {
        if (ind - 1 > n)
            return;
        if (res.size() == k) {
            ans.push_back(res);
            return;
        }
        res.push_back(ind);
        rec(n, k, res, ind + 1);
        res.pop_back();
        rec(n, k, res, ind + 1);

        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        rec(n, k, res, 1);
        return ans;
    }
};
