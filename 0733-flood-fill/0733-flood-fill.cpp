class Solution {
    
    void bfs(int m, int n,  queue<pair <int, int> > &pixels, int color, vector<vector<int>> &image,  int pixelColor ){
        
        vector<pair<int, int> > directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        
        
        while(!pixels.empty()){
            int size = pixels.size();
            
                while(size--){
                    auto [x,y] = pixels.front();
                    pixels.pop();
                    
                    for(auto dir : directions){
                        int newX = dir.first + x;
                        int newY = dir.second + y;
                        
                        if(newX >= 0 && newY >= 0 && newX < m && newY < n && image[newX][newY] == pixelColor){
                            image[newX][newY] = color;
                            pixels.push({newX, newY});
                        }
                    }
                    
                }   
        }
    }
    
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        queue<pair <int, int> > pixels;
        pixels.push({sr, sc});
        
        int pixelColor = image[sr][sc];
        image[sr][sc] = color;
        
        if(pixelColor != color){
            bfs(m, n, pixels, color, image, pixelColor);
        }
        
        
           
        
        
        return image;
    }
};