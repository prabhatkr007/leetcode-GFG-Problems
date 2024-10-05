class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26), v2(26);
        
        for(char c : s1) {
            v1[c - 'a']++;
        }
        
        int i = 0;
        int j = 0;
        int n = s2.size();
        int k = s1.size();
        
        while(j < n){
            
             v2[s2[j] -'a']++;
            
            if(j-i+1 == k){
                if(v1 == v2) return true;
                v2[s2[i] -'a']--;
                i++;
            }
            
            j++;
        }
        
        return false;
    }
};