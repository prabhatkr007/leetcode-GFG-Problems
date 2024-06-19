class Solution {
     int robHelper(const vector<int>& nums, int start, int end, vector<int>& memo) {
        if (start > end) return 0; 
        if (memo[start] != -1) return memo[start]; 

        // Rob current house
        int robCurrent = nums[start] + robHelper(nums, start + 2, end, memo); 
        // Skip current house
        int skipCurrent = robHelper(nums, start + 1, end, memo); 

        return memo[start] = max(robCurrent, skipCurrent); 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 

        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);
        int robFirstExcluded = robHelper(nums, 1, n - 1, memo1); 
        int robLastExcluded = robHelper(nums, 0, n - 2, memo2); 

        return max(robFirstExcluded, robLastExcluded);
    }

};