//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    
    long long sum(long long n){
        
        if ( n == 0 ){
            return 0;
        }
        
        
        
        long long total = sum(n-1);
        
        total = total + n*n*n;
        
        return total;
        
        
        
    }
  public:
    long long sumOfSeries(long long N) {
        
        // code here
        
        
        return sum (N);
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends