class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map, map2;
        
        for( int i = 0; i < s.length(); i++){
            if(map.find(s[i]) != map.end()){
                if(map[s[i]] != t[i]) return false;
            }
             if(map2.find(t[i]) != map2.end()){
                if(map2[t[i]] != s[i]) return false;
            }
            map[s[i]] = t[i];
            map2[t[i]] = s[i];
            
          }
        return true;
    }
};