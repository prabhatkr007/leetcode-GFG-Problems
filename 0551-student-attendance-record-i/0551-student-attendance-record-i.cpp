class Solution {
public:
    bool checkRecord(string s) {
        int abs = 0, late = 0;
        
        for(char ch : s){
            if(ch == 'A'){
                abs++;
                late = 0;
                if(abs >=2) return false;
            }
            
            if(ch == 'L'){
                late++;
                if(late >= 3){
                    return false;
                }
            }
            
            if(ch == 'P'){
                late = 0;
            }
        }
        
        return true;
    }
};