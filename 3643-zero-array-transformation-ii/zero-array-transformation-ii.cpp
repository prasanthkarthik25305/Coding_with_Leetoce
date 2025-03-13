#include <vector>
#include <numeric>  // For accumulate

using namespace std;

class Solution {
public:
    bool predicate(int mid, int n, vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> pref(n + 1, 0);  

        // Apply range updates using difference array technique
        for (int i = 0; i <= mid; i++) {
            pref[queries[i][0]] += queries[i][2];
            if (queries[i][1] + 1 < n) { 
                pref[queries[i][1] + 1] -= queries[i][2];
            }
        }

        // Compute prefix sum to get final array state
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }

        // Check if nums[i] can be reduced to zero or below
        for (int i = 0; i < n; i++) {
            if (nums[i] > pref[i]) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);  
        if (sum == 0) return 0;

        int n = nums.size();
        int res = -1, l = -1, r = queries.size();  
        while (l + 1 < r) {  
            int mid = (l + r) / 2;
            if (predicate(mid, n, nums, queries)) {
                r = mid; 
            } else {
                l = mid; 
            }
        }

        // `r` is now the smallest valid index
        return (r == queries.size()) ? -1 : r + 1;
    }
};
