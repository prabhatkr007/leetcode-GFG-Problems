class Solution {
   
    int xorsum(vector<int> &subset){
        int tempSum = 0;  
        
        for(int i = 0; i < subset.size(); i++){
            tempSum ^= subset[i];  
        }
        return tempSum;
    }

  
    void subsetUtil(int start, vector<int>& nums, vector<int>& subset, int & sum){
      
        sum += xorsum(subset);
        
        for(int i = start; i < nums.size(); i++){
            
            subset.push_back(nums[i]);
            subsetUtil(i + 1, nums, subset, sum);
            subset.pop_back();
        }
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        vector<int> subset;
        
       
        subsetUtil(0, nums, subset, sum);
        
        return sum;
    }
};
