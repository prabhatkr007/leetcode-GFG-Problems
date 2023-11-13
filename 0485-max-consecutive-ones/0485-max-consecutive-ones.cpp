class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt= 0;
        int maxcount = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == 1){
                cnt++;
                maxcount = max(cnt, maxcount);
            }else{    
                cnt= 0;
            }
        }
        
        return maxcount;
    }
};