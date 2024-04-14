class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> s;
        
        long long curr = 0;
        int n = nums.size();
        
        for(int i=0;i<k;i++){
            s[nums[i]]++;
            curr+=nums[i];
        }
        
        long long maxi = 0;
        
        if(s.size()==k){
            maxi = max(maxi, curr);
        }
        
        for(int i=k;i<n;i++){
            s[nums[i-k]]--;
            curr-=nums[i-k];
            
            curr+=nums[i];
            s[nums[i]]++;
            
            if(s[nums[i-k]]==0){
                s.erase(nums[i-k]);
            }
            
            if(s.size()==k){
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};