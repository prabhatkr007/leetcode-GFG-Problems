class Solution {
public:
    bool isAnagram(string s, string t) {
        //storing all char on hashmap
        
        unordered_map<char, int> m;
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        
        //check every element for second string
        
        for(int i = 0; i < t.size(); i++){
            auto it = m.find(t[i]);
            
            if(it != m.end()){
                if(it -> second > 0){
                    m[t[i]]--;
                    continue;
                }else return false;
            }else{
                return false;
            }
        }
        
        return true;
        
    }
};