class Solution {
public:
   vector<bool>chk;
bool dfs(int node, int destination, vector<vector<int>>& adj) {
    chk[node] = true;

    for (auto neighbor : adj[node]) {
        if (!chk[neighbor]) {
            
             dfs(neighbor, destination, adj);
            
        }
    }
    return chk[destination];
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { 
        chk.resize(n+1,false);
        vector<vector<int>>adj(n+1);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

       return dfs(source,destination,adj);
    }
};