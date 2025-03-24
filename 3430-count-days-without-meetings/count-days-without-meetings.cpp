class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> events;
        
        for (auto &m : meetings) {
            events.push_back({m[0], 1});  
            events.push_back({m[1] + 1, -1}); 
        }
        
        // Sort events by day
        sort(events.begin(), events.end());

        int cnt = 0, ans = 0, last = 1; 
        for (auto &e : events) {
            int day = e.first, type = e.second;

            // If no active meeting, count the free days in between
            if (cnt == 0 && day > last) {
                ans += day - last;
            }
            
            cnt += type; 
            last = day; 
        }
        
        // Handle remaining days if last event < total days
        if (last <= days) {
            ans += days - last + 1;
        }
        
        return ans;
    }
};
