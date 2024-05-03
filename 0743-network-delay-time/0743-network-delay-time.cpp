class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed graph
        vector<int> dist(n + 1, INF);
        
        // Build the graph
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph[u].push_back({v, w});
        }
        
        // Min-heap to store {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k}); // Starting from source node with time 0
        dist[k] = 0; // Shortest time to reach source node is 0
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (time > dist[node]) {
                continue;
            }
            
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int nextTime = time + neighbor.second;
                
                if (nextTime < dist[nextNode]) {
                    dist[nextNode] = nextTime;
                    pq.push({nextTime, nextNode});
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) {
                return -1; // Not all nodes are reachable
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
    
};