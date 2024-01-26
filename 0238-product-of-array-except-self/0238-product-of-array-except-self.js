/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const n = nums.length;
    const answer = new Array(n).fill(1);
    
    // we setting prev value to one before first element there will be nothing
    let prev = 1;
    // store prefix product in answer array
    for(let i = 0; i < n; i++) {
        answer[i] *= prev;
        prev *= nums[i];
    }
    
    // we setting prev value to one before first element there will be nothing
    let suf = 1;
    // store suffix product in answer array
    // the answer[i] already have prefix
    for(let i = n - 1; i >= 0; i--) {
        answer[i] *= suf;
        suf *= nums[i];
    }
    
    return answer;
};

// tc -> O(n)
// sc -> O(1)