/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const n = nums.length;
    const answer = new Array(n);
    const prefix = new Array(n).fill(1);
    const suffix = new Array(n).fill(1);
    
    // create a prefix array
    // prefix array will have the product of all element before an index i 
    for(let i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    
    // create a suffix array 
    // suffix array will have the prodict of all element before an index i 
    for(let i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }
    
    // populate the answers array 
    for(let i = 0; i < n; i++) {
        answer[i] = prefix[i] * suffix[i];
    }
    
    return answer;
};

// tc -> O(n)
// sc -> O(n)