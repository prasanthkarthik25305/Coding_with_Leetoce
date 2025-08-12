class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[301][301];
    vector<int> power;

    int rec(int num, int sum, int n) {
        if (sum == n)
            return 1;
        if (sum > n || num >= power.size())
            return 0;

        if (dp[num][sum] != -1)
            return dp[num][sum];

        long long res = 0;
        if (sum + power[num] <= n)
            res += rec(num + 1, sum + power[num], n);
        res += rec(num + 1, sum, n);

        return dp[num][sum] = res % mod;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
       // power.clear();
        power.push_back(0); // index 0 unused

        for (int i = 1;; i++) {
            long long val = 1;
            for (int j = 1; j <= x; j++)
                val *= i;
            if (val > n)
                break; // stop early to keep power small
            power.push_back((int)val);
        }

        return rec(1, 0, n);
    }
};
