class Solution {
    void backtrack(const string& digits, const vector<string>& mapping, string& current, int index, vector<string>& result) {

        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[(digits[index] -'0')];
        
        for (char letter : letters) {
            current.push_back(letter); 
            backtrack(digits, mapping, current, index + 1, result);  
            current.pop_back();  
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Mapping of digits to letters
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string current;
        backtrack(digits, mapping, current, 0, result);
        return result;
    }
};
