//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
//User function Template for C

//Function to arrange all letters of a string in lexicographical 
//order using Counting Sort.

void countingSort(char arr[], int size){
    int count[26] = {0};
    
    for(int i = 0; i < size; i++){
        count[arr[i]-'a']++;
    }
    
    
    int index = 0;
    for(int i = 0; i < 26; i++){
        
        if(count[i] > 0){
            while(count[i]--){
            arr[index++] = i+'a';
            }
            
           
        }
        
    }
}


char* countSort(char arr[]){
    
    int size = strlen(arr);
    countingSort(arr, size);
    return arr;
    
    
}

//{ Driver Code Starts.

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		char str[n+1];
		scanf("%s", str);
		printf("%s\n", countSort(str));

	}
	return 0;

}
// } Driver Code Ends