class Solution {
public:
    vector<int> twoSum(vector<int>& input, int target) {
        unordered_map<int, int> map;

    for(int i = 0 ; i < input.size(); i++){
        if(map.find(target - input[i]) == map.end()){
            map[input[i]] = i;
        }else{
            return {i, map[target - input[i]]};
        }
    }
    return{-1, -1};
    }
};