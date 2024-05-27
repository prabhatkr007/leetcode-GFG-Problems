class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count = 0;
        
        for(int x = 0 ; x <=nums.size(); x++){
            int count = 0;
            for(int num : nums){
                
              if(num >= x)  {
                  count++;
              }
            }
            
            if(count == x) return x;
        }
        
        return -1;
    }
};