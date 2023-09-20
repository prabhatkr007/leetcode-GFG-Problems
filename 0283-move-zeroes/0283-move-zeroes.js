/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let p = 0;
    
    for(let i = 0; i < nums.length; i++){
        
        if(nums[i] != 0){
            
            let temp = 0;
            
            temp = nums[p];
            nums[p] = nums[i];
            nums[i] = temp;
            
            p++;
        }
    }
};