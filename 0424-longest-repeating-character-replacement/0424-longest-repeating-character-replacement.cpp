class Solution {
public:
   int characterReplacement(string s, int k) {
    int i = 0;
    int j = 0;
    int n = s.size();
    int maxi = 0; 
    int maxLength = 0;
    unordered_map<char, int> m;

    while (j < n) {
        m[s[j]]++;
        maxi = max(maxi, m[s[j]]);  

        if ((j - i + 1) - maxi <= k) {
            maxLength = max(maxLength, j - i + 1);
         }
        
        else if ((j - i + 1) - maxi > k) {
            while((j - i + 1) - maxi > k){
                m[s[i]]--;
                if (m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
           
        }

        j++;
    }

    return maxLength;
}

};