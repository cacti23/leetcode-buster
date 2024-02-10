/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let left = 0, right = 0, sum = 0;
    let n = nums.length;
    
    // find the total sum
    for(let i = 0; i < n; i++) {
        right += nums[i];
    }

    
    // right value can be treated as a first value of a suffix array
    
    for(let i = 0; i < n; i++) {
        // subtracting nums[i] so that the right values has sum from i + 1 to n
        right -= nums[i];
        if(right === left) return i;
        // adding value to the left to that it has value of 0 to i for next iteration
        left += nums[i];
    }
    
    return -1;
};

// draw this on a notebook
// tc -> O(n)
// sc -> O(1)