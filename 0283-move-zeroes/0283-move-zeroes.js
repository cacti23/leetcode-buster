/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let l = nums.length;
    let i = 0;
    for(let j = 1; j < l; j++) {
        if(nums[i] == 0 && nums[j] !== 0) {
            let t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
        } else if(nums[i] !== 0 && nums[j] === 0) {
            i = j;
        }
    }
    
    return;
};

// tc -> O(n)
// sc -> O(1)