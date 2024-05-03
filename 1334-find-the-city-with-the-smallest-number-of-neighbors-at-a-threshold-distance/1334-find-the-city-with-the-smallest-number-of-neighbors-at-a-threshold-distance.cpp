class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         // Initialize the adjacency matrix with maximum distances
        vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max() / 2));
        
        // Initialize diagonal elements to 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Update distances based on given edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd-Warshall's algorithm to find shortest paths between all pairs of cities
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int minNeighbors = n;
        int cityWithMinNeighbors = -1;
        
        // For each city, count the number of reachable cities within the distance threshold
        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }
            if (reachableCities <= minNeighbors) {
                minNeighbors = reachableCities;
                cityWithMinNeighbors = i;
            }
        }
        
        return cityWithMinNeighbors;
    }
    
};