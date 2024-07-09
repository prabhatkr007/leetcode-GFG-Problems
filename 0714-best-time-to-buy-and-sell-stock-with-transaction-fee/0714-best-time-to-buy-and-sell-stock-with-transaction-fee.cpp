class Solution {
public:
    int dp(vector<int>& prices, int index, bool holding, int fee, vector<vector<int>>& memo) {
    if (index >= prices.size()) {
        return 0; 
    }
        
    if (memo[index][holding] != -1) {
        return memo[index][holding];
    }

    int doNothing = dp(prices, index + 1, holding, fee, memo);
    if (holding) {
        // We are currently holding a stock, so we can sell it
        int sell = prices[index] - fee + dp(prices, index + 1, false, fee, memo);
        memo[index][holding] = max(doNothing, sell);
    } else {
        // We are not holding a stock, so we can buy it
        int buy = -prices[index] + dp(prices, index + 1, true, fee, memo);
        memo[index][holding] = max(doNothing, buy);
    }

    return memo[index][holding];
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> memo(n, vector<int>(2, -1)); 
    return dp(prices, 0, false, fee, memo);
}

};