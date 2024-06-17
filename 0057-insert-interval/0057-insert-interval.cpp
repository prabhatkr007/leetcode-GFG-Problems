class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;

        // Step 1: Insert the new interval in the correct position
        for (const auto& interval : intervals) {
            if (!inserted && newInterval[0] < interval[0]) {
                result.push_back(newInterval);
                inserted = true;
            }
            result.push_back(interval);
        }
        
        if (!inserted) {
            result.push_back(newInterval);
        }

        // Step 2: Merge overlapping intervals
        vector<vector<int>> merged;
        for (const auto& interval : result) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
        
    
};