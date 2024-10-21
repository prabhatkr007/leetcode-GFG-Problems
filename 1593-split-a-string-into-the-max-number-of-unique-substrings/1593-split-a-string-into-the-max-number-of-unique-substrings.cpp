class Solution {
        void backtrack(int start, string &s, unordered_set<string> &currentSet, int &count) {
        if (start == s.size()) {
            count = max(count, (int)currentSet.size());
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            string substring = s.substr(start, i - start + 1); 
        
            if (currentSet.find(substring) == currentSet.end()) {
                
                currentSet.insert(substring);
                backtrack(i + 1, s, currentSet, count);
                currentSet.erase(substring); 
            }
        }
    }
    
public:
    int maxUniqueSplit(string s) {
        
        int count = 0;
        unordered_set<string> currentSet;
        
        backtrack(0, s, currentSet, count);
        return count;
    
    }
};