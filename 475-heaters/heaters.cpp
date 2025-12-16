class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        int m = heaters.size();

        for (int h : houses) {
            int idx = lower_bound(heaters.begin(), heaters.end(), h) - heaters.begin();

            int dist = INT_MAX;

            // right heater
            if (idx < m)
                dist = abs(heaters[idx] - h);

            // left heater
            if (idx > 0)
                dist = min(dist, abs(heaters[idx - 1] - h));

            ans = max(ans, dist);
        }

        return ans;
    }
};
