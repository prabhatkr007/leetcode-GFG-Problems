class Solution {
public:
    int strStr(string haystack, string needle) {
    int pos = haystack.find(needle);
    if (pos != string::npos) {
        return pos;
    } else {
        return -1;
    }
    }
};