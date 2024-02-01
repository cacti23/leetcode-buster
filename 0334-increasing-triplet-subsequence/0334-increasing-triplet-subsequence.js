/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    if(nums.length < 3) return false;
    
    let a = Number.MAX_SAFE_INTEGER;
    let b = Number.MAX_SAFE_INTEGER;
    
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] <= a) a = nums[i];
        else if(nums[i] <= b) b = nums[i];
        else return true;
    }
    
    return false;
};

// It works because, whenever we update b, it means we we've already found a number a<b, and, whenever we get to the else block, it means we've already got two numbers, a and b, which are smaller than this number, c. So, now we've got c>a and c>b and having a b ensures there's also an a<b that comes before b. So, we've found our pattern.
// tc -> O(n)
// sc -> O(1)