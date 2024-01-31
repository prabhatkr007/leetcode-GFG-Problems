class Solution {

    bool solve(vector <int> &nums, int sum, int i,vector <vector<int>> &dp){

        if (sum == 0)
        return true;

        if (i == 0 && sum != 0)
        return false;
 
        if( dp[i][sum] != -1){
            return dp[i][sum];
        }

        if (nums[i] > sum)
        return dp[i][sum] = solve(nums, sum, i-1, dp);
        
        return dp[i][sum] =  (solve(nums, sum - nums[i],i-1,dp)|| solve(nums,sum,i-1,dp));

       
        
    }
public:
    bool canPartition(vector<int>& nums) {
        

        int i = nums.size()-1;
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2 != 0){
            return false;
        }
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));

        return solve(nums,sum/2,i,dp);
       
        
    }
};