class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         if (original.size() != m * n) {
            return {}; 
        }
        
        vector<vector<int>> arr(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++) {
            arr[i /n][i % n] = original[i];
           
        }
        
        return arr;
           
    }
};