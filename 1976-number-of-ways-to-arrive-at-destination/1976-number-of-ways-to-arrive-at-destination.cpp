class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        vector<long long> shortestTime(n, numeric_limits<long long>::max());
        vector<int> ways(n, 0);
        
        ways[0] = 1; 
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // Starting from source node with time 0
        shortestTime[0] = 0; // Shortest time to reach source node is 0
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                long long nextTime = time + neighbor.second;
                
                if (nextTime < shortestTime[nextNode]) {
                    shortestTime[nextNode] = nextTime;
                    ways[nextNode] = ways[node]; 
                    
                    pq.push({nextTime, nextNode});
                } else if (nextTime == shortestTime[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod; // Accumulate number of ways
                }
            }
        }
        
        return ways[n - 1];
    }
    
};