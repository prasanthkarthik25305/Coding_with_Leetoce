class Solution {
    private:
    void generateStates(int m, int row, int prevColor, int curr, vector<int>& state, vector<vector<int>>& states) {
        if (row == m) {
            states.push_back(state);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (color != prevColor) {
                state.push_back(color);
                generateStates(m, row + 1, color, curr * 3 + color, state, states);
                state.pop_back();
            }
        }
    }

    bool isValidTransition(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == b[i]) return false;
        return true;
    }
public:
    int mod = 1e9 + 7;

    int colorTheGrid(int m, int n) {
        vector<vector<int>> states;
        vector<int> tmp;
        generateStates(m, 0, -1, 0, tmp, states);
        int sz = states.size();

        vector<vector<int>> compatible(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (isValidTransition(states[i], states[j])) {
                    compatible[i].push_back(j);
                }
            }
        }

        vector<int> dp(sz, 1); // base case: 1 way to color first column
        for (int col = 1; col < n; ++col) {
            vector<int> newDp(sz, 0);
            for (int i = 0; i < sz; ++i) {
                for (int j : compatible[i]) {
                    newDp[i] = (newDp[i] + dp[j]) % mod;
                }
            }
            dp = newDp;
        }

        int ans = 0;
        for (int count : dp) {
            ans = (ans + count) % mod;
        }

        return ans;
    }


};
