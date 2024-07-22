class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        vector<pair<int, int>> pairs;
        
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        for(auto pair : freq){
            pairs.push_back({pair.second, pair.first});
        }
        
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
            if (a.first == b.first) {
                return a.second > b.second;  
            }
            return a.first < b.first; 
        });
        
        for(auto pair : pairs){
            int f = pair.first;
            while(f--){
                ans.push_back(pair.second);
            }
        }
        return ans;
    }
};