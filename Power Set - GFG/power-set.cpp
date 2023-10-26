//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    void solve(string input, string output, vector<string> & ans, int i){
        
        if(input.size() == i){
            if(output != "")
            ans.push_back(output);
            return ;
        }
        
        solve(input, output + input[i], ans, i+1);
        solve(input, output, ans, i+1);
        
        
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string out;
		    
		   
		    solve(s, out, ans, 0);
		   
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