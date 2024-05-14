class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m, vector<pair<int, int>> &directions,  vector<vector<bool>> &visited) {
        
        int curr = grid[i][j];
        visited[i][j] = true; // Mark as visited

        int localMaxGold = 0;
        for (auto direction : directions) {
            int dx = i + direction.first;
            int dy = j + direction.second;

            if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] != 0 && visited[dx][dy] == false) {
                localMaxGold = max(localMaxGold, dfs(dx, dy, grid, n, m,
                                                     directions, visited));
            }
        }

        visited[i][j] = false; // mark as not visited for revisit from another path
        return curr + localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxGold = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(i, j, grid, n, m,
                                               directions, visited));
                }
            }
        }

        return maxGold;
    }
};