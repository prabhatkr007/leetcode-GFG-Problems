class Solution {
public:
    int minimumPushes(string word) {
        
        unordered_map<char, int> frequency;
        for (char c : word) {
            frequency[c]++;
        }
  
        vector<int> freqList;
        for (const auto& p : frequency) {
            freqList.push_back(p.second);
        }
        
        sort(freqList.rbegin(), freqList.rend());
   
        int res = 0;
        int layer = 1;
        int accumulated = 0;
    
        for (int freq : freqList) {
            res += freq * layer;
            accumulated++;
        
            if (accumulated == 8) {
                layer++;
                accumulated = 0;
            }
        }
    
        return res;
    }
};