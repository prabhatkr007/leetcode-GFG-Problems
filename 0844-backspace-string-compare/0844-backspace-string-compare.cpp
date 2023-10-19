class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sizeS = s.length();
        int sizeT = t.length();
        
        string temp1 ;
        string temp2 ;
  
        
        for(int i = 0; i< sizeS; i++){
            
           if(s[i] == '#'){
               if(temp1.size()){
                   temp1.pop_back();
               }
               
           }else{
              temp1.push_back(s[i]);
           }
            
        }
        
        for(int i = 0; i < sizeT; i++){
            if(t[i] == '#'){
                
                if(temp2.size()){
                temp2.pop_back();
                }
            }else{
                temp2.push_back(t[i]);
            }
        }
        if(temp1.size() == temp2.size()){
            if(temp1 == temp2) return true;
        }
        
        
        return false;
    }
};