class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = INT_MAX;
        if(nums[start] < nums[end]) return nums[start];
        
        while (start <= end) {
            
            int mid = start + (end - start) / 2;
            
            if(nums[start] <= nums[mid]){
                ans = min(nums[start], ans);
                start = mid + 1;
            }
            else {
                ans = min(nums[mid], ans);
                end = mid -1;
            }
        }
        
        return ans;
    }

};