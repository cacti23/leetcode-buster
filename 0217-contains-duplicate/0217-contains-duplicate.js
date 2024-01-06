/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    // using sets 
    const uniqueElements = new Set(nums);
    
    return nums.length != uniqueElements.size;
};

// tc -> O(n* logn)
// sc -> O(1)
