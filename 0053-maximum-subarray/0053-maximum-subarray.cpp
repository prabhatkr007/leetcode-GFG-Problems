class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        	
	int Max = arr[0];
	int currSum = 0;
	for(int i = 0; i < arr.size(); i++){
		if(currSum < 0){
		currSum = 0;
}
		currSum += arr[i];
	Max = max(currSum, Max );	
	}
return Max;

    }
};