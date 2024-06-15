class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minIndex = 0;
        
        for(int i = 0; i< nums.size(); i++){
            if( i> minIndex) return false;
            
            minIndex = max(nums[i] +i,minIndex );
            
        }
        
        return true;
    }
};