class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> counts;
        priority_queue<pair<int , char>> sortedList;
        
        for(int i = 0; i < s.length(); i++){
            counts[s[i]]++;
        }
        
        for(auto count : counts){
            sortedList.push({count.second, count.first});
        }
        
        string ans;
        
        while(!sortedList.empty()){
           auto temp = sortedList.top();
            while(temp.first --){
                ans.push_back(temp.second);
            }
            sortedList.pop();
        }
        
        return ans;
    }
};