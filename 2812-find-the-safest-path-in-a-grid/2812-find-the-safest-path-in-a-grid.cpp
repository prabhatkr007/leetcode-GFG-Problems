class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize the BFS from all thief locations
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Perform BFS to compute the minimum distance to any thief for each cell
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && distance[nx][ny] > distance[x][y] + 1) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start from the top-left corner
        pq.push({distance[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto [current_safeness, cell] = pq.top();
            pq.pop();
            auto [x, y] = cell;
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            // If we reach the bottom-right corner, return the safeness factor
            if (x == n-1 && y == n-1) {
                return current_safeness;
            }
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    pq.push({min(current_safeness, distance[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return 0;
    }
};