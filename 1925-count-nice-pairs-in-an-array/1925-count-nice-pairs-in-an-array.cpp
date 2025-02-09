class Solution {

    int rev(int num){
        string s = to_string(num);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> mp;

        for(int i = 0 ; i < nums.size(); i++){
            int key = nums[i] - rev(nums[i]);
            mp[key]++;
        }
    
        long long nicePairs = 0;
        for (auto& p : mp) {
            long long count= p.second;
            nicePairs += (count*(count - 1))/2;
        }

        return nicePairs % MOD;

    }
};