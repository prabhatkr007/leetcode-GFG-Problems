const int MOD = 1e9 + 7;

class Solution {
     int dp(int n, int a, int l, vector<vector<vector<int>>>& memo) {
        if (n == 0) return 1;
        if (memo[n][a][l] != -1) return memo[n][a][l];
        
        int res = 0;
        res = (res + dp(n - 1, a, 0, memo)) % MOD;
        
       
        if (a < 1) {
            res = (res + dp(n - 1, a + 1, 0, memo)) % MOD;
        }
        
        
        if (l < 2) {
            res = (res + dp(n - 1, a, l + 1, memo)) % MOD;
        }
        
        memo[n][a][l] = res;
         
        return res;
    }
    
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dp(n, 0, 0, memo);
    }

};