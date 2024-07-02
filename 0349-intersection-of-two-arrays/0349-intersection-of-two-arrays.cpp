class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> ans;
        
        for(int num : nums1){
            set.insert(num);
        }
        
        for(int num : nums2){
            if(set.find(num) != set.end()){
                ans.push_back(num);
                set.erase(num);
            }
        }
        
        return ans;
    }
};