
class Solution {
     int canBreak(int start, const string& s, const set<string>& wordSet,   vector<int> &dp) {
    
        if (start == s.size()) {
            return 1;
        }
         
         if(dp[start] != -1) return dp[start];
         
        string temp;
        
        for (int i = start; i < s.size(); ++i) {
            temp += s[i];
           if(wordSet.find(temp) != wordSet.end()){
               if(canBreak(i+1, s, wordSet, dp)) return dp[start] = 1;
           }
            
        }
        
         return dp[start] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto str : wordDict) st.insert(str);
        vector<int> dp (301, -1);
        return canBreak(0, s, st, dp);
        
    }
   
};
