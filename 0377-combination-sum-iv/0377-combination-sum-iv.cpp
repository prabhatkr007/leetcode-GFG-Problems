class Solution {
    int util(vector<int>& nums, int target, unordered_map<int, int>& memo) {
    
        if (target == 0) {
            return 1;
        }
        
    
        if (memo.find(target) != memo.end()) {
            return memo[target];
        }
        
        
        int count = 0;
        
    
        for (int i =0; i < nums.size(); i++) {
            if (target >= nums[i]) {
             
                count += util(nums, target - nums[i], memo);
            }
        }
          memo[target] = count;
        
        return count;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return util(nums, target, memo);
    }
};