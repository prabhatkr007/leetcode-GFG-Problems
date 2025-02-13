class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double half = sum/2;

        priority_queue<double> pq(nums.begin(), nums.end());

        int count = 0;

        while(sum >half){
            double ele = pq.top(); pq.pop();
            sum -= ele;
            double tempHalf = ele/2;
            sum += tempHalf;
            count++;
            pq.push(tempHalf);
        } 

        return count;   
        
    }
        
};