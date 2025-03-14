class Solution {
public:
    bool predicate(int mid, vector<int>& candies, long long k) {
        long long count = 0;
        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid; 
        }
        return count >= k; 
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = accumulate(candies.begin(), candies.end(), 0LL);
        
        if (total_candies < k) return 0;  

        int low = 0, high = *max_element(candies.begin(), candies.end()), mid;
        high++;
        while (low+1 < high) {
            mid = (low + high) / 2;            
            if (predicate(mid, candies, k)) {
                low = mid; 
            } else {
                high = mid; 
            }
        }
        return low;
    }
};
