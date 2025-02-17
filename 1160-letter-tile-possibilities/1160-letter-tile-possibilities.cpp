class Solution {
    void backtrack(unordered_map<char, int>& freq, int& count) {
    for (auto& [ch, f] : freq) {
        if (f > 0) {
            freq[ch]--;  
            count++;     
            backtrack(freq, count); 
            freq[ch]++;
        }
    }
}
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        
        for (char ch : tiles) {
            freq[ch]++;  
        }

        int count = 0;
        backtrack(freq, count);
        return count;
    }
};