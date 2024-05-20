#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));  // Create an empty n x n board
        vector<int> columns(n, 0);                // Track columns used by queens
        vector<int> diag1(2 * n - 1, 0);          // Track left-to-right diagonals
        vector<int> diag2(2 * n - 1, 0);          // Track right-to-left diagonals

        backtrack(result, board, columns, diag1, diag2, 0, n);
        return result;
    }

private:
    void backtrack(vector<vector<string>>& result, vector<string>& board, vector<int>& columns, vector<int>& diag1, vector<int>& diag2, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (columns[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue; // If the column or diagonals are occupied, skip this position
            }

            // Place the queen
            board[row][col] = 'Q';
            columns[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + n - 1] = 1;

            // Move to the next row
            backtrack(result, board, columns, diag1, diag2, row + 1, n);

            // Backtrack: remove the queen and reset the states
            board[row][col] = '.';
            columns[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + n - 1] = 0;
        }
    }
};
