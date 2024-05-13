class Solution {
    void toggleRow( vector<vector<int>>& grid, int row) {
        for (int j = 0; j < grid[row].size(); ++j) {
            grid[row][j] = 1 - grid[row][j];
        }
    }
    
    void toggleColumn(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); ++i) {
            grid[i][col] = 1 - grid[i][col];
        }
    }
    
    int binaryToDecimal(vector<int>& binary) {
        int decimal = 0;
        for (int i = 0; i < binary.size(); ++i) {
            decimal += binary[i] * pow(2, binary.size() - 1 - i);
        }
        
        return decimal;
    }
    
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //Ensure all rows start with 1 
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                toggleRow(grid, i);
            }
        }
        
        //Toggle columns if needed to maximize 1s
        for (int j = 1; j < n; ++j) {
            int ones = 0;
            for (int i = 0; i < m; ++i) {
                ones += grid[i][j];
            }
            // Toggle the column if there are more zeros than ones
            if (ones < m - ones) {
                toggleColumn(grid, j);
            }
        }
        
        //Calculate the score
        int score = 0;
        for (int i = 0; i < m; ++i) {
            score += binaryToDecimal(grid[i]);
        }
        
        return score;
    }     


};