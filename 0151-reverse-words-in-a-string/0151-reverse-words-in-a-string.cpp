class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string ans = "";
        string str = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    temp.push_back(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }

        if (!str.empty()) {
            temp.push_back(str);
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            ans += temp[i];
            if (i > 0) {
                ans += ' ';
            }
        }

        return ans;
    }
};
