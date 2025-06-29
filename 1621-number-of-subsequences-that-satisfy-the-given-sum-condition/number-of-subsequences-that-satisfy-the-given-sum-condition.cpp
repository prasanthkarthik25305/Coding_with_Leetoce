class Solution {
public:
    static constexpr int MOD = 1e9 + 7;


    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1) 
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1;
        long long cnt = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                cnt = (cnt + modPow(2, j - i)) % MOD;
                i++;
            } else {
                j--;
            }
        }

        return (int)cnt;
    }
};
