/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    // sort the array 
    nums.sort((a, b) => a - b);
    
    // check for adjacent duplicates using some
    
    return nums.some((_, i) => nums[i] === nums[i + 1]);
};

// tc -> O(nlogn)
// sc -> O(1)
