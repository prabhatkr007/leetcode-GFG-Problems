class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = INT_MAX;
        int picIndex = -1;
        int largest = INT_MIN;
        int ans = 0;
        
        for(int i = 0; i < arrays.size(); i++){
           if(smallest > arrays[i][0]){
               smallest = arrays[i][0];
               picIndex = i;
           }
            
            
        }
        
        for(int i = 0; i < arrays.size(); i++){
        
            if(picIndex != i){
                largest = max( largest, arrays[i][arrays[i].size()-1]);
                 ans = max(abs( largest- smallest) , ans);
            }
            
          
            
        }
        
        smallest = INT_MAX;
        picIndex = -1;
        largest = INT_MIN;
        int ans1 = 0;
        
        for(int i = 0; i < arrays.size(); i++){
           if(largest < arrays[i][arrays[i].size()-1]){
               largest = arrays[i][arrays[i].size()-1];
               picIndex = i;
           }
            
            
        }
        
        for(int i = 0; i < arrays.size(); i++){
        
            if(picIndex != i){
                smallest = min( smallest, arrays[i][0]);
                 ans1 = max(abs( smallest- largest) , ans);
            }
            
          
            
        }
        return max(ans, ans1);
    }
};