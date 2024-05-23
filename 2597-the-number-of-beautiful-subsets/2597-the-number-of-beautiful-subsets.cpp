
class Solution {
    bool isBeautifulSubset(const vector<int>& subset, int k) {
        for (int i = 0; i < subset.size(); i++) {
            for (int j = i + 1; j < subset.size(); j++) {
                if (abs(subset[j] - subset[i]) == k) {
                    return false;
                }
            }
        }
        return true;
    }

    void backtrack(int start, vector<int>& nums, int k, vector<int>& current, int& count) {
        if (isBeautifulSubset(current, k)) {
            count++;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, k, current, count);
            current.pop_back();
        }
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<int> current;
        backtrack(0, nums, k, current, count);
        return count - 1; // Subtract 1 to exclude the empty subset
    }
};
