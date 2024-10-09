class Solution {
public:
    int numberOfSubstrings(string s) {
         int i = 0; 
        int j = 0;
        int n = s.size();
        unordered_map<char, int> m;
        int ans = 0;

        while (j < n) {
            m[s[j]]++;  

            while (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {
                ans += (n - j);
                m[s[i]]--;
                i++;
            }

            j++;  
        }

        return ans;
    }
};