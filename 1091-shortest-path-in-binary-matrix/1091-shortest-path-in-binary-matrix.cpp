class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                                             {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        
        queue<pair<pair<int, int>, int>> q; // (coordinates, distance)
        q.push({{0, 0}, 0}); 
        grid[0][0] = 1; // Mark as visited
        
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1) {
                return distance + 1;
            }

            for (const auto& dir : directions) {
                int newr = row + dir.first;
                int newc = col + dir.second;
                
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && 
                    grid[newr][newc] == 0 && distance + 1 < dist[newr][newc]) {
                    
                    dist[newr][newc] = distance + 1;
                    q.push({{newr, newc}, distance + 1});
                }
            }
        }
        
        return -1;
    }
};
