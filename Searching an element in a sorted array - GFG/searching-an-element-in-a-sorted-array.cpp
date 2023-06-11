//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       int flag = -1;
       int left = 0;
       int right = N-1;
       
       for (int i = 0 ; i < N; i++){
           
           int mid = left + (right-left)/2;
           
           if(K > arr[mid]){
               left = mid+1;
           }
           
            if(K < arr[mid]){
                right = mid -1;
            }
           
           if( K == arr[mid]){
               return 1;
               break;
           }
           
       }
       
      return flag; 
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends