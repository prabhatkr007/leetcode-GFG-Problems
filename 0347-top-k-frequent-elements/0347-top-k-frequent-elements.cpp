class Solution {
    
  
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> map;
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(int num: nums ){
            map[num]++;
        }
            
        for(auto value : map)   {
            minHeap.push({value.second, value.first});
            
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty()){
            auto temp = minHeap.top();
            ans.push_back(temp.second);
            minHeap.pop();
            
        }
        
        return ans;
        
      
    }
};