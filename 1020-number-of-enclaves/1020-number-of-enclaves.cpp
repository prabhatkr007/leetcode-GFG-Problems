#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, 
             vector<vector<int>>& visited,vector<pair<int, int>>& directions) {
        int m = grid.size();
        int n = grid[0].size();
    
        visited[row][col] = 1; // Mark as visited
    
        for(auto dir : directions){
            int newx = row + dir.first;
            int newy = col + dir.second;
            
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && 
               grid[newx][newy] == 1 && visited[newx][newy] == 0){
                dfs(newx, newy, grid, visited, directions);
            }
        }
    }
      
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0)); 
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // DFS from boundary cells
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, visited, directions);
            if (grid[i][n - 1] == 1)
                dfs(i, n - 1, grid, visited, directions);
        }
        
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1)
                dfs(0, j, grid, visited, directions);
            if (grid[m - 1][j] == 1)
                dfs(m - 1, j, grid, visited, directions);
        }
        
        // Count remaining land cells
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                    count++;
            }
        }
        
        return count;
    }
};
