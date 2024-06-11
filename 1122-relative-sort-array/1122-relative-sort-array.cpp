class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        
        vector<int> ans;
        
        for(int ele : arr1){
            map[ele]++;
        }
        
        for(int ele : arr2){
            int freq = map[ele];
            while(freq--){
                ans.push_back(ele);
 
            }
            map.erase(ele);
        }
        
        for(auto ele : map){
            int element = ele.first;
            int freq = ele.second;
            
            while(freq--){
                ans.push_back(element);
            }
        }
    
        return ans;
    }
};