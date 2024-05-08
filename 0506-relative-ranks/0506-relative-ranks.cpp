class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        priority_queue<pair<int, int>> pq; //{score, index}
        vector<string> ans (size);
        
        for(int i = 0; i < size; i++){
            pq.push({score[i], i});
        }
        
        // removing element from the max heap one by one
        
        for(int i = 1; i <=size; i++){
            auto info = pq.top();
            int index = info.second;
            int score = info.first;
            pq.pop();
            
            
            if(i <= 3){
                if(i == 1) ans[index] = "Gold Medal";
                if(i == 2) ans[index] = "Silver Medal";
                if(i == 3) ans[index] = "Bronze Medal";
            }else{
                ans[index] = to_string(i);
            }
        }
        
        return ans;
    }
};