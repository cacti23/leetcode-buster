/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let i = 0, l = nums.length, zerosInWindow = 0, max = 0;
    
    for(let j = 0; j < l; j++) {
        // if we witness zeros inside the window of i and j increase the value
        if(nums[j] === 0) {
            zerosInWindow++;
        }
        
        if(zerosInWindow > 1) {
            // before increasing i make sure if we leave zero outside the window we should decrease the number
            if(nums[i] === 0) zerosInWindow--;
            i++;
        }
        
        if(zerosInWindow <= 1) {
            // here we are doing j - i not j - i + 1 becuase we want to eliminate the element
            max = Math.max(max, j - i);
        }
    }
    
    return max;
};

// the question can be thought as the longest subarray with at most 1 zeros
// tc -> O(n)
// sc -> O(1)