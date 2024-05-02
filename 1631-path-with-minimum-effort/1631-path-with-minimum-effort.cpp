class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> efforts(rows, vector<int>(cols, numeric_limits<int>::max()));
        
        // Min-heap to store {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}}); // Starting from top-left cell with effort 0
        efforts[0][0] = 0; // Effort required to reach top-left cell is 0
        
        // Possible directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();
            
            int row = cell.first;
            int col = cell.second;
            
            // Check if reached bottom-right cell
            if (row == rows - 1 && col == cols - 1) {
                return effort;
            }
            
            // Check neighbors
            for (const auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));
                    if (newEffort < efforts[newRow][newCol]) {
                        efforts[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        
        return -1; // If no path found
    }
};