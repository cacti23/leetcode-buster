/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let zerosInWindow = 0, i = 0, l = nums.length, max = 0;
    
    for(let j = 0; j < l; j++) {
        // if we witness zeros inside the window of i and j increase the value
        if(nums[j] === 0) zerosInWindow++;
        
        if(zerosInWindow > k) {
            // before increasing i make sure if we leave zero outside the window we should decrease the number
            if(nums[i] === 0) zerosInWindow--;
            i++;
        }
        
        // if zerosInWindow between i and j is less than k we can consider them as the part of the answer
        if(zerosInWindow <= k) {
            max = Math.max(max, j - i + 1);
        } 
    }
    
    return max;
};

// the question can be thought as the longest subarray with at most k zeros
// tc -> O(n)
// sc -> O(1)