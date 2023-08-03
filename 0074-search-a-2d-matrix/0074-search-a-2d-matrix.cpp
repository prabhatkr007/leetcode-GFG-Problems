class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0; 
        int high = n*m -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(matrix[mid/n][mid%n] == target) {
                return true;
            }
            
            
            if(matrix[mid/n][mid%n] < target) {
                low = mid+1;
                
            }
            else{
                high = mid -1;
            }
            
        }
        return false;
        
        
        
        
        
        
    }
};