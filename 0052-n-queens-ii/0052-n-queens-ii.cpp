
class Solution {
     void backtrack(int n, int row, vector<int>& columns, vector<int>& diag1, vector<int>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!columns[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
            // Place the queen
            columns[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + n - 1] = 1;

            // Move to the next row
            backtrack(n, row + 1, columns, diag1, diag2, count);

            // Backtrack
            columns[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + n - 1] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> columns(n, 0);               
        vector<int> diag1(2 * n - 1, 0);          
        vector<int> diag2(2 * n - 1, 0);         
        int count = 0;                           

        backtrack(n, 0, columns, diag1, diag2, count);
        return count;
    }
   
};
