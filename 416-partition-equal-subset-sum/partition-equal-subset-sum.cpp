class Solution {
public:
    vector<vector<int>> dp;

    bool rec(vector<int>& nums, int i, int sum, int tar) {
        int n = nums.size();
        if (sum == tar) return true;
        if (i >= n || sum > tar) return false;
        
        if (dp[i][sum] != -1) return dp[i][sum];

        bool include = rec(nums, i + 1, sum + nums[i], tar);
        bool exclude = rec(nums, i + 1, sum, tar);

        return dp[i][sum] = (include || exclude);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;

        int tar = sum / 2;
        int n = nums.size();
        dp.resize(n, vector<int>(tar + 1, -1));

        return rec(nums, 0, 0, tar);
    }
};