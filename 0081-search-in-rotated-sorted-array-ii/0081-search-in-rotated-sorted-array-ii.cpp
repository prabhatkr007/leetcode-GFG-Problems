class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        
        while (low <= high) {
            int mid = (low + high) / 2;


            if (nums[mid] == target) {
                return true;
               
            }
            
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
        }
            //left sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    //element exists:
                    high = mid - 1;
                }
                else {
                    //element does not exist:
                    low = mid + 1;
                }
            }
            
            else { //if right part is sorted:
                if (nums[mid] <= target && target <= nums[high]) {
                    //element exists:
                    low = mid + 1;
                }
                else {
                    //element does not exist:
                    high = mid - 1;
                }
            }
        }
    return false;
    }
};