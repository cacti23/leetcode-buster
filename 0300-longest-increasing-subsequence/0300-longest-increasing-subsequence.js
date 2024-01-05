/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const n = nums.length;
    // this array keep the longest increasing subsequence for each index of the array 
    const dp = new Array(n).fill(1);
    
    for(let i = n - 1; i >= 0; i--) {
        for(let j = i + 1; j < n; j++) {
            if(nums[i] < nums[j]) {
                dp[i] = Math.max(dp[i], 1 + dp[j]);
            }
        }
    }
    
    // max of dp will be the answer
    return Math.max(...dp);
};

// tc -> O(n^2)
// sc -> O(n)