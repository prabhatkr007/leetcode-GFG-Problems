class Solution {
public:
    string firstPalindrome(vector<string>& words) {
          for(auto s : words){
            string temp = s;
            reverse(temp.begin(),temp.end());  
            if(temp == s){
                return s;
            }
        }
        return "";
    }
    
};