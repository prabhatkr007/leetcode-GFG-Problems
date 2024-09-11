class Solution {
    
    void backtrack(int start,vector<int>& candidates, int target,vector<vector<int> > &result, vector<int> &temp  ){
        if(target == 0){
            result.push_back(temp);
        }
        
        if(target < 0){
            return;
        }
        
        for(int i = start; i< candidates.size(); i++){
            if(i > start &&  candidates[i] == candidates[i-1]) continue;
            
            if(target >= candidates[i]){
                temp.push_back(candidates[i]); // take
                backtrack(i + 1, candidates, target-candidates [i], result, temp);
                temp.pop_back() ;// not take
            }
           
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(0, candidates, target, result, temp);
        
        return result;
    }
};