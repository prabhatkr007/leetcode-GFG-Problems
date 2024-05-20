class Solution {
public:
     void backtrack(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& result) {
         
        result.push_back(temp);
         
        for (int i = start; i < nums.size(); ++i) { 
                temp.push_back(nums[i]);
                backtrack(nums, i + 1, temp, result);
                temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(nums, 0, temp, result);
        return result;
    }
};