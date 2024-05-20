class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(const string& s, int start, int count, vector<vector<int>>& memo, bool& found) {
        if (count == 3 && start == s.size()) {
            found = true;
            return;
        }
        if (count == 3 || start == s.size()) {
            return;
        }

        if (memo[start][count] != -1) {
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                backtrack(s, end + 1, count + 1, memo, found);
                if (found) {
                    return;
                }
            }
        }

        memo[start][count] = found ? 1 : 0;
    }

    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(3, -1)); // Memo table initialized to -1
        bool found = false;
        backtrack(s, 0, 0, memo, found);
        return found;
    }
};