class Solution {
public:
    int longestPalindrome(string s) {
         unordered_map<char, int> charCount;
    
        for (char c : s) {
            charCount[c]++;
        }

        int length = 0;
        bool oddFound = false;

        for (auto count : charCount) {
            if (count.second % 2 == 0) {
                length += count.second; 
            } else {
                length += count.second - 1;
                oddFound = true;
            }
        }
        
        if (oddFound) {
            return length + 1;
        }

        return length;
        }
};