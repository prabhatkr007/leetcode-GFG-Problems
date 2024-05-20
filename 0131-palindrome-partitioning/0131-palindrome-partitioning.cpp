class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void util(string& s, int start, vector<string>& temp, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                util(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        util(s, 0, temp, ans);
        return ans;
    }
};
