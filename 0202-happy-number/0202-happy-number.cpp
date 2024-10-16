class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumSq(n);
        }
        
        return n == 1;
    }

    int sumSq(int s) {
        int sum = 0;
        while (s != 0) {
            int digit = s % 10;
            sum += (digit * digit);
            s /= 10;
        }
        return sum;
    }
};