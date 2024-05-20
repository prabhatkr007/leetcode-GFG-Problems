class Solution {
public:
    bool search(int i, int j, const string &word, vector<vector<bool>> &visited, const vector<vector<char>> &board, const vector<pair<int, int>> &directions, int index) {
        int n = board.size();
        int m = board[0].size();
        
        if (board[i][j] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        visited[i][j] = true;

        for (auto direction : directions) {
            int dx = i + direction.first;
            int dy = j + direction.second;

            if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]) {
                if (search(dx, dy, word, visited, board, directions, index + 1)) {
                    return true;
                }
            }
        }

        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (search(i, j, word, visited, board, directions, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};