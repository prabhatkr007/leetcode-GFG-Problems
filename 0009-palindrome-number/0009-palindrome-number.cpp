class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long int temp = x;
        long int num=0;
        while(temp){
        	num = (num *10) + (temp%10);
            temp=temp/10;
        }
        
        
        if(num == x ){
            return true;
        }
        else{
            return false;
        }
    }
        
    
};