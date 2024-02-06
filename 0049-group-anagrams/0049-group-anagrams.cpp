class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int> > map;
        vector<vector<string> > ans;
        
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            
            sort(temp.begin(), temp.end());
            
            map[temp].push_back(i);
        }
        
        for(auto data : map){
            auto indexes =  data.second;
            vector<string> temp;
            for(int index : indexes){
                temp.push_back(strs[index]);
                
            }
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};