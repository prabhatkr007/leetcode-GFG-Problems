class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int num :nums){
             mp[num]++;
        }
           
        int ans=0;
        for(auto x : mp){
            if(k==0){    
                if(x.second>=2) ans++;
            }
             else if(mp.find(x.first+k)!=mp.end()) ans++;
        }
        
        return ans;
    }
        
};