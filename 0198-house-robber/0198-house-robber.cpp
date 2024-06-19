class Solution {
     int robFrom(vector<int>& nums, int i,vector<int>& memo) {
        if (i < 0) return 0; 
        if (memo[i] != -1) return memo[i];
        
        // Rob current house and move to the house before the previous one
        int robCurrentHouse = nums[i] + robFrom(nums, i - 2, memo); 
        // Skip current house and move to the previous one
        int skipCurrentHouse = robFrom(nums, i - 1, memo); 
        
        return memo[i] = max(robCurrentHouse, skipCurrentHouse); ; 
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 
        if (n == 1) return nums[0]; 
        
        vector<int> memo(n, -1);  
        return robFrom(nums, n - 1, memo);
    
    }
};