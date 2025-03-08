class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0; int j = 0;
        int n = blocks.size();
        int white = 0;
        int ans = INT_MAX;

        while(j < n){

            if(blocks[j] == 'W' ) white++;
            
            if(j - i + 1 == k){
                ans = min(ans , white);

                if(blocks[i] == 'W'){
                    white--;
                }

                i++;             
            }

            j++;

        }

        return ans;
    }
};