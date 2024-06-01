class Solution {
public:
    int countGoodSubstrings(string s) {
    if (s.length() < 3) {
         return 0;  
    }
        int count = 0;
        for (int i = 0; i <= s.length() - 3; ++i) {
            
            unordered_set<char> charSet;
            
            string substr = s.substr(i, 3);
            for (char c : substr) {
                charSet.insert(c);
            }
            if (charSet.size() == 3) {
                ++count;
            }
        }
        return count;
    }
};