class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rotationCount = 0;

        for (int i = 1; i < n ; i++) {
            if (nums[i-1] > nums[i]) {
                rotationCount++;
            }
        }
        cout<<rotationCount;
        if (rotationCount > 1) {
            return false;
        }

        if (rotationCount == 1) {
            return nums[n - 1] <=nums[0];
        }

        return true;
    }
};
