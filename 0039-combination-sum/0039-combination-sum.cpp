class Solution {
    void util(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int start) {
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        for(int i = start; i < candidates.size(); i++){
        if (target >= candidates[i]) {
            temp.push_back(candidates[i]);
     
            util(candidates, target - candidates[i], ans, temp, i);
      
            temp.pop_back();
        }
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        util(candidates, target, ans, temp, 0);
        return ans;
        
    }
};
