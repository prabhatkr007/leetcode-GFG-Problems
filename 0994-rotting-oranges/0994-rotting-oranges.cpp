class Solution {
    void bfs(int m, int n, int &freshOranges,  queue<pair<int,int>> &rottenQueue , int &minutes, vector<vector<int>>& grid ){
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!rottenQueue.empty()){
            int size = rottenQueue.size();
            bool flag = false;
            
            while(size--){
                auto [x, y] = rottenQueue.front();
                rottenQueue.pop();
            
                for(auto dir : directions ){
                
                int newI = dir.first + x;
                int newJ = dir.second + y;
                
                if(newI >= 0 && newJ >= 0 && newI < m && newJ < n && grid[newI][newJ] == 1){
                    grid[newI][newJ] = 2;
                    freshOranges --;
                    rottenQueue.push({newI, newJ});
                    flag = true;
                }
            }
                    
        }
            
            if(flag == true){
                     minutes++;
                }
                          
        }
                
    }
    
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int minutes = 0;
        int freshOranges = 0;
        int m = grid.size() ;
        int n = grid[0].size();
        
        queue<pair<int,int> >rottenQueue;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++ ){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                
                if(grid[i][j] == 2){
                    rottenQueue.push({i,j});
                }
            }
        }
        
        
        if(freshOranges > 0){
            bfs(m, n, freshOranges,rottenQueue,minutes, grid );
        }
        
        
        return freshOranges == 0 ? minutes : -1;
        
    }
};