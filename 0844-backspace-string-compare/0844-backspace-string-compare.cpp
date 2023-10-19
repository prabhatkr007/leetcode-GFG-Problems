class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1, temp2;
        
        for(char c : s){
            
           if(c == '#'){
               if(temp1.size()){
                   temp1.pop_back();
               }
               
           }else{
              temp1.push_back(c);
           }
            
        }
        
        for(char c : t){
            if(c == '#'){
                
                if(temp2.size()){
                temp2.pop_back();
                }
            }else{
                temp2.push_back(c);
            }
        }
      
        return temp1 == temp2;
    }
};