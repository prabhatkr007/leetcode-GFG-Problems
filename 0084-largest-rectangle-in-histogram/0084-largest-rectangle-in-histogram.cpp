class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());
        
        // NSL
        stack<int> stack1;
        for (int i = 0; i < heights.size(); i++) {
            while (!stack1.empty() && heights[stack1.top()] >= heights[i]) {
                stack1.pop();
            }
            if (!stack1.empty()) {
                left[i] = stack1.top();
            }
            stack1.push(i);
        }

        // NSR
        stack<int> stack2;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stack2.empty() && heights[stack2.top()] >= heights[i]) {
                stack2.pop();
            }
            if (!stack2.empty()) {
                right[i] = stack2.top();
            }
            stack2.push(i);
        }

        vector<int> width(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            width[i] = right[i] - left[i] - 1;
        }

        vector<int> area(heights.size());
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            area[i] = heights[i] * width[i];
            maxArea = max(maxArea, area[i]);
        }
        return maxArea;
    }
};