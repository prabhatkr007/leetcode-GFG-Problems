class Solution {
    vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int max_moves = 0;
        for (auto [di, dj] : directions) {
            int ni = i + di;
            int nj = j + dj;
            
            if (ni >= 0 && ni < grid.size() && nj < grid[0].size() && grid[ni][nj] > grid[i][j]) {
                max_moves = max(max_moves, 1 + dfs(ni, nj, grid, memo));
            }
        }
        
        return  memo[i][j] = max_moves;
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        
        for (int i = 0; i < rows; i++) {
            ans = max(ans, dfs(i, 0, grid, memo));
        }
        
        return ans;
    }
};