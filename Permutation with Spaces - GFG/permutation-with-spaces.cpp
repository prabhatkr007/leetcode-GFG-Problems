//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void solve(string in , string op, vector<string> &ans){
        if(in.length() == 0){
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        op1.push_back(' ');
        op1.push_back(in[0]);
        
        op2.push_back(in[0]);
        
        in.erase(in.begin() + 0);
        
        solve(in, op1, ans);
        solve(in, op2, ans);
        
        
    }

    vector<string> permutation(string S){
        // Code Here
        vector<string> ans;
        string in = S;
        string op ;
        
        
        op.push_back(in[0]);
        
        in.erase(in.begin()+0);
        
        solve(in,op,ans);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends