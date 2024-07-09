class Solution {
public:
   int dp(vector<int>& nums, int index, int prevIndex, vector<vector<int>>& memo) {
    if (index == nums.size()) {
        return 0;
    }

    if (memo[index][prevIndex + 1] != -1) {
        return memo[index][prevIndex + 1];
    }

    // Exclude the current element
    int exclude = dp(nums, index + 1, prevIndex, memo);

    // Include the current element if it is greater than the previous element in the sequence
    int include = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        include = 1 + dp(nums, index + 1, index, memo);
    }

    memo[index][prevIndex + 1] = max(exclude, include);

    return memo[index][prevIndex + 1];
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    return dp(nums, 0, -1, memo);
    }
};