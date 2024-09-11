class Solution {
     void util( int start, int target, vector<vector<int>>& ans, vector<int>& temp, int k) {
        
        if(target == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        
        if(target <0 || k < 0){
            return;
        }
        
        for(int i = start; i < 10; i++){
            if(i <= target){
                temp.push_back(i);  // take  
                util(i+1, target - i, ans, temp,  k -1);
                temp.pop_back(); // not take
            }
            
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        util(1, target, ans, temp, k);
        return ans;
    }
};