class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int , string, greater<int>> m;
        vector<string> ans;
        
        for(int i = 0 ; i < names.size(); i++){
            m[heights[i]] = names[i];
        }
        
        for(auto pair : m){
            ans.push_back(pair.second);
        }
        
        return ans;
        
    }
};