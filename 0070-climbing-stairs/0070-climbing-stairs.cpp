class Solution {
    int foo(int n , vector<int> &dp){
    if ( n<0 ){
            return 0;
        }

        if (n == 0){
            return 1;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        dp[n] = foo(n-1, dp) + foo(n-2, dp);
        return dp[n];
    }

    
public:
    int climbStairs(int n) {

        vector<int> dp (n+1, -1);

        int ans = foo(n, dp);
        return ans;
        
    }
};