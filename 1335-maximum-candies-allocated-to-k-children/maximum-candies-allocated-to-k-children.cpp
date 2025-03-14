class Solution {
public:
    bool predicate(int mid, vector<int>& candies, long long k) {
        long long count = 0;
        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid;  // Count how many children can get `mid` candies
        }
        return count >= k;  // True if we can distribute at least `k` children
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = accumulate(candies.begin(), candies.end(), 0LL);
        if (total_candies < k) return 0;  // Not enough candies for every child

        int low = 1, high = *max_element(candies.begin(), candies.end()), mid;
        
        while (low <= high) {
            mid = low + (high - low) / 2;  // Avoid overflow

            if (predicate(mid, candies, k)) {
                low = mid + 1;  // Try to increase candies per child
            } else {
                high = mid - 1;  // Reduce search space
            }
        }

        return high;  // `high` will hold the max valid candies per child
    }
};
