class Solution {
public:
    string removeKdigits(string num, int k) {
    vector<char> st;

    for (char digit : num) {
        while (k > 0 && !st.empty() && st.back() > digit) {
            st.pop_back();
            k--;
        }

        // Skip adding leading zeros
        if (!st.empty() || digit != '0') {
            st.push_back(digit);
        }
    }

    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    string result = "";
    for (char digit : st) {
        result += digit;
    }

    return result.empty() ? "0" : result;
}
    
};