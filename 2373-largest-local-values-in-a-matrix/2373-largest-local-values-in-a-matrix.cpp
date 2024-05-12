class Solution {
    
public:
    int getMax(int x , int y, vector<vector<int>>& grid){
 
        int n = grid.size();
        int maxi = grid[x][y];
        
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int dx = x + i;
                int dy = y + j;
                if(dx >= 0 && dx < n && dy >=0 && dy < n ){
                    maxi = max(grid[dx][dy], maxi);
                }
                
            }
        }
        
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int> > maxLocal(n-2, vector<int> (n-2));
        
        for(int i = 0; i< n-2; i++){
            for(int j = 0; j < n-2; j++){
                maxLocal[i][j] = getMax(i+1, j+1, grid);
            }
        }
        
        
        return maxLocal;
    }
};