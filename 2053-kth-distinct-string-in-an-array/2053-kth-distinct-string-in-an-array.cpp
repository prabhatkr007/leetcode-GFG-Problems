class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        
        for(string ele : arr){
            map[ele]++;
        }
        int count= 0;
        for(auto str : arr){
            if(map[str] == 1){
                count++;
                if(count == k) return str;
            }
        }
        return "";
    }
};