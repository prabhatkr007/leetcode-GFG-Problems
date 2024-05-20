#include <vector>
#include <utility> // for pair
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& grid, int row, int col, int emptyCount, int& pathCount, vector<pair<int, int>>& directions) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        // If the current cell is the ending square and all empty squares are visited
        if (grid[row][col] == 2) {
            if (emptyCount == 0) {
                pathCount++;
            }
            return;
        }
        
        // Mark the current cell as visited
        grid[row][col] = -1;
        

        for (const auto& dir : directions) {
            int nextRow = row + dir.first;
            int nextCol = col + dir.second;

            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && grid[nextRow][nextCol] != -1) {
                dfs(grid, nextRow, nextCol, emptyCount - 1, pathCount, directions);
            }
        }
        
        grid[row][col] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startRow, startCol, emptyCount = 0;
        
        // Find the starting square and count the number of empty squares
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                } else if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }
        
        int pathCount = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        dfs(grid, startRow, startCol, emptyCount + 1, pathCount, directions); 
        return pathCount;
    }
};
