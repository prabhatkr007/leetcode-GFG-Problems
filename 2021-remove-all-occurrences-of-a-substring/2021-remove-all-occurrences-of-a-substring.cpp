class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack;
        int targetLength = part.size();
        char endChar = part.back();

        for (char currentChar : s) {
            stack.push_back(currentChar);

            if (currentChar == endChar && stack.size() >= targetLength) {
                if (stack.substr(stack.size() - targetLength) == part) {
                    stack.erase(stack.size() - targetLength);
                }
            }
        }
        
        return stack;    
    }
};