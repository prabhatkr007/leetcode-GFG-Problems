class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        
        for(int x :nums)
            s.insert(x);
    
    int ans = 0;
    for(int i= 0 ; i < nums.size(); i++){
        
        int curr = nums[i];
        int prev_ele = curr - 1;
        
        int count = 0;
        
        if(s.find(prev_ele) == s.end()){
            while(s.find(curr) != s.end()){
                curr++;
                count ++;
            }
            ans = max(ans, count);
        }
    }
        return ans;
    }
};