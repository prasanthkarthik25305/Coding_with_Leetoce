class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;   // cycle found
        if (state[node] == 2) return false;  // already visited, no cycle

        state[node] = 1;  // mark as visiting

        for (int nei : adj[node]) {
            if (dfs(nei, adj, state)) return true;
        }

        state[node] = 2;  // mark as fully visited
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build adjacency list (b -> a)
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0); // 0 = not visited, 1 = visiting, 2 = visited

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) return false; // cycle detected
            }
        }
        return true; // no cycle
    }
};
