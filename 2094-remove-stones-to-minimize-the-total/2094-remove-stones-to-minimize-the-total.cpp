class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin(), piles.end(), 0);

        priority_queue<int> pq(piles.begin(),piles.end());

        while(k--){
            int ele = pq.top();
            pq.pop();
            int half = ceil(ele/2.0);
            sum -= ele;
            sum += half;
            pq.push(half);

        }

        return sum;
    }
};