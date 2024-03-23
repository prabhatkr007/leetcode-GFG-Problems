class Solution {
    
    int sumByD(vector<int> &arr, int div, int threshold) {
        int n = arr.size(); 
 
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil(static_cast<double>(arr[i]) / static_cast<double>(div));
        }
        return sum;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid, threshold) <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};