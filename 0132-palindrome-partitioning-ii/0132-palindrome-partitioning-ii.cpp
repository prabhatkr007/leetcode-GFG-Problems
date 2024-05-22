class Solution {
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minPartitions(int start, string &str,  vector<int> &dp) {
        if (start == str.size()) return 0;
        if (dp[start] != -1) return dp[start];
        
        int minCost = INT_MAX;
        
        for (int i = start; i < str.size(); i++) {
            if (isPalindrome(start, i, str)) {
                int cost = 1 + minPartitions(i + 1, str, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[start] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
            
        return minPartitions(0, s, dp) - 1;
    }
};