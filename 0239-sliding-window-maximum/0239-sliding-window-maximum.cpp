#include <vector>
#include <list>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        std::list<int> ls;
        std::vector<int> ans;
        
        while (j < nums.size()) {
            // Remove elements smaller than the current one from the back
            while (!ls.empty() && ls.back() < nums[j])
                ls.pop_back();
            
            ls.push_back(nums[j]); // Add current element
            
            if (j - i + 1 < k) { 
                j++;
            } else { 
                ans.push_back(ls.front()); 
                
                // If the element going out of the window was the maximum,
                // remove it from the front of the list
                if (nums[i] == ls.front())
                    ls.pop_front();
                
                i++; 
                j++; 
            }
        }
        
        return ans;
    }
};
