class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         if (original.size() != m * n) {
            return {}; 
        }
        
        vector<vector<int>> arr(m, vector<int>(n));
        int r = 0;
        for (int i = 0; i < original.size(); i++) {
            arr[r][i % n] = original[i];
            if (i % n == n - 1) r++;
        }
        
        return arr;
           
    }
};