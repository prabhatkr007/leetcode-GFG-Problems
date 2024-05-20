class Solution {
public:
    void backtrack(const string& s, int start, string& temp, vector<string>& result) {          if(s.size() == temp.size()){
           result.push_back(temp);
         }
           
            for (int i = start; i < s.size(); ++i) {
                if(isalpha(s[i])){
                    temp.push_back(toupper(s[i]));
                    backtrack(s, i + 1, temp, result);
                    temp.pop_back();


                    temp.push_back(tolower(s[i]));
                    backtrack(s, i + 1, temp, result);
                    temp.pop_back();
            }else{
                    temp.push_back((s[i]));
                    backtrack(s, i + 1, temp, result);
                    temp.pop_back();
                }
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string temp;
        backtrack(s, 0, temp, result);
        return result;
    }
};
