class Solution {
    vector<string> canBreak(int start, const string& s, const set<string>& wordSet, vector<vector<string>>& dp) {
        if (start == s.size()) {
            return {""};
        }
        
        if (!dp[start].empty()) {
            return dp[start];
        }
        
        vector<string> result;
        string temp;
        
        for (int i = start; i < s.size(); ++i) {
            temp += s[i];
            if (wordSet.find(temp) != wordSet.end()) {
                vector<string> nextSentences = canBreak(i + 1, s, wordSet, dp);
                for (const string& sentence : nextSentences) {
                    result.push_back(temp + (sentence.empty() ? "" : " " + sentence));
                }
            }
        }
        
        dp[start] = result;
        return result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(s.size(), vector<string>());
        return canBreak(0, s, wordSet, dp);
    }
};
