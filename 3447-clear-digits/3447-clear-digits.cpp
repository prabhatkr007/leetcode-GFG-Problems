class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(char &c : s){
            if(isdigit(c)){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
           
        }
        
        if(st.empty()) return "";
        else{
            string ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};