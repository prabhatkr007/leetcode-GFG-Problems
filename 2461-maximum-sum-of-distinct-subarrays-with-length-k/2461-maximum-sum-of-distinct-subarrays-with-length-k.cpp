class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int i = 0;
        int j = 0;
        long long sum = 0, mx = INT_MIN; 
        unordered_map<int, int> map;
    
        while (j < nums.size()) {
            sum += nums[j];
            map[nums[j]]++;
            
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                
               if(map.size()==k){
                    mx =max(mx,sum);
                }
                
                map[nums[i]]--;
                
               if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
            
                sum -= nums[i];
                i++;
                j++;
            }
        }
        
        return mx == INT_MIN ? 0 : mx ;
    }
};