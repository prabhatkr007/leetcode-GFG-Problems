class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair <int, int> ppi;

        unordered_map <int,int> map;

        priority_queue<ppi , vector<ppi> , greater<ppi> > minh;
        vector<int> ans;

        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]]++;
        }

        for(auto i = map.begin(); i != map.end(); i++){
            minh.push({i->second, i->first});

            if(minh.size() > k){
                minh.pop();
            }
        }

        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans; 
    }
};