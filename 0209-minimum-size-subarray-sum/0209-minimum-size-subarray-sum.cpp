class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, current_sum = 0, min_length = INT_MAX;
        int j = 0;
        
        while (j < n) {
            
            current_sum += nums[j];
            
            if(current_sum < target){
                j++;
            }
            else if((current_sum >= target)){
                while (current_sum >= target) {
                    min_length = min(min_length, j - i + 1);
                    current_sum -= nums[i++];
                    }
                    j++;
            }
            
        }
        
        return (min_length == INT_MAX) ? 0 : min_length;
    }
    
};