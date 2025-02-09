class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long  goodPairs = 0,  n = nums.size();

        for(int i = 0; i < n; i++){
            goodPairs += mp[nums[i] - i];
            mp[nums[i] - i]++;
        }

        return (n * (n - 1)) / 2 - goodPairs;
    }
};