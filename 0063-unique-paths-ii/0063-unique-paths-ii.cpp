#include <vector>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& obstacleGrid, int row, int col, vector<pair<int, int>>& directions, vector<vector<int>>& memo) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (row == m - 1 && col == n - 1) {
            return 1;
        }
        
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        
        int count = 0;
        for (const auto& dir : directions) {
            int nextRow = row + dir.first;
            int nextCol = col + dir.second;
            
            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && obstacleGrid[nextRow][nextCol] == 0) {
                count += dfs(obstacleGrid, nextRow, nextCol, directions, memo);
            }
        }
        
        memo[row][col] = count;
        return count;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}}; // Right and Down
        vector<vector<int>> memo(m, vector<int>(n, -1)); // Memoization table
        
        return dfs(obstacleGrid, 0, 0, directions, memo);
    }
};
