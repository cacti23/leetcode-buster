/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const flag = false;
    const n = nums.length;
    
    for(let i = 0; i < n; i++) {
        for(let j = i + 1; j < n; j++) {
            if(nums[i] == nums[j]) return true;
        }
    }
    
    return false;
};

// tc -> O(n^2);
// sc -> O(1)