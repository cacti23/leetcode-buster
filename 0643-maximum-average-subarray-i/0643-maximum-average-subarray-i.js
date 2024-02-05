/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    const l = nums.length;
    let sum = 0;
    let res = Number.MIN_SAFE_INTEGER;

    for (let i = 0; i < l; i++) {
       if(i < k) {
           sum += nums[i];
       } else {
           res = Math.max(res, sum);
           sum = sum - nums[i - k] + nums[i];
       }
    }
    
    res = Math.max(sum, res);    
    return (res / k);
};

// tc -> O(n)
// sc -> O(1)

