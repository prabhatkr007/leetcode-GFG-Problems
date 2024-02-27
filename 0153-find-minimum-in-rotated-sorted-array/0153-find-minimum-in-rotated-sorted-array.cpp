class Solution {
public:
    int findMin(vector<int>& nums) {
         int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum must be in the right half
            left = mid + 1;
        } else {
            // Minimum must be in the left half or at mid
            right = mid;
        }
    }

    return nums[left];
    }
};