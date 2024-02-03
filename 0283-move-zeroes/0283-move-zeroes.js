/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let l = nums.length;
    let insertPos = 0;
    for(let i = 0; i < l; i++) {
        if(nums[i] !== 0) {
            nums[insertPos] = nums[i];
            insertPos++;
        }
    }
    
    // copy zeros at end
    while(insertPos < l) {
        nums[insertPos] = 0;
        insertPos++;
    } 
    
    return;
};

// tc -> O(n)
// sc -> O(1)