class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        
        for(int ele : asteroids){
            if(ele > 0){
                s.push(ele);
            }else{
                
                while(!s.empty()&& s.top() > 0 && s.top() < abs(ele)){
                    s.pop();
                }
                
                if(!s.empty() && s.top() == abs(ele)){
                    s.pop();
                }
                
                else if(s.empty() || s.top() < 0 ){
                    s.push(ele);
                }
            }
        }
        vector<int> ans(s.size());
        
        for(int i = s.size() - 1; i >= 0; i--){
            ans[i] = s.top();
            s.pop();
        }
        
        return ans;
    }
};