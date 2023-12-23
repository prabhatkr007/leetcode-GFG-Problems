class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //store these values in hashpmap
        
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        
        // iterate over the array and check the freq. of elements
        
        for(int i = 0; i < nums.size(); i++){
        
            auto it = m.find(nums[i]);
            
            if(it -> second != 1){
                return true;
            }
        }
        
        return false;
        
    }
};