class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> pq;
        int n = happiness.size();
        
        for(int i = 0; i < n; i++){
            pq.push(happiness[i]);
        }
        int decrement = 0;
        long long ans = 0;
        
        while(!pq.empty() && k){
            long long h = pq.top();
            pq.pop();
            
            if(h - decrement > 0){
                ans = ans + h - decrement;
            }
            
            decrement++;
            k--;
        }
        return ans;
    }
};