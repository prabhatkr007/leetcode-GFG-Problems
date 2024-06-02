class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int n = s.length();

        while (start < n) {
          
            while (end < n && s[end] != ' ') {
                ++end;
            }
  
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            ++end;
        }

        return s;
    }
};