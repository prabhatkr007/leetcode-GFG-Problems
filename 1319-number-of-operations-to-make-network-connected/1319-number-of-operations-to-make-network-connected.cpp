class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, adj, visited);
                }
            }
        }
    
    public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1) {
            return -1;
        }
        
        // Create adjacency list for the graph
        vector<vector<int>> adj(n);
        for (const auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        // Count the number of connected components using DFS
        vector<bool> visited(n, false);
        int components = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }
        
        // The minimum number of operations needed is components - 1
        return components - 1;
    }
};