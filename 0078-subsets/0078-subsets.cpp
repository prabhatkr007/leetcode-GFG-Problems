class Solution {
public:
    void backtrack(const vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& result) {
      
        if (index == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        backtrack(nums, index + 1, temp, result);
        temp.pop_back(); 
        backtrack(nums, index + 1, temp, result);
    }
    
    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(nums, 0, temp, result);
        return result;
    }
};
