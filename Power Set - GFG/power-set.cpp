//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    void solve(string input, string output, vector<string> & ans){
        
        if(input.length() == 0 ){
            if(output != "")
            ans.push_back(output);
            return ;
        }
        
        string op1 = output;
        string op2 = output;
        op2.push_back(input[0]);
        
        input.erase(input.begin() + 0);
        
        solve(input, op1, ans);
        solve(input, op2, ans);
        
        
        
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string out;
		    
		    
		    
		    solve(s, out, ans);
		   
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends