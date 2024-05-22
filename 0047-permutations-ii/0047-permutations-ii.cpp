#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
       
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used;
        
        for (int i = start; i < nums.size(); ++i) {
            // If the element has already been used in this depth, skip it
            if (used.find(nums[i]) != used.end()) continue;
            
            used.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};
