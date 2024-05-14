class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int curr = grid[i][j];
        grid[i][j] = 0; // Mark as visited

        int localMaxGold = 0;
        for (auto direction : directions) {
            int dx = i + direction.first;
            int dy = j + direction.second;

            if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] != 0) {
                localMaxGold = max(localMaxGold, dfs(dx, dy, grid, n, m));
            }
        }

        grid[i][j] = curr; // Restore original value
        return curr + localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxGold = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(i, j, grid, n, m));
                }
            }
        }

        return maxGold;
    }
};