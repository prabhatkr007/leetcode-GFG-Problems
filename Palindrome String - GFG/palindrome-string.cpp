//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    stack <char> s;
	    
	    for(int i = 0; i < S.length(); i++){
	        s.push(S[i]);
	        
	    }
	    string val;
	    for(int i = 0; i < S.length(); i++){
	        
	        val.push_back(s.top());
	        s.pop();
	        
	    }
	    
	    if(S == val){
	        return 1;
	    }
	    else{
	        return 0;
	    }
	    
	    
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends