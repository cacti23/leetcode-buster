/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    const mp = new Map();
    
    for(let n of nums) {
        mp.set(n, (mp.get(n) || 0) + 1);
    }
    
    let ans = 0;
    for(let [key, value] of mp.entries()) {
        if(value === 1) return -1;
        ans += Math.ceil(value / 3);
    }
    
    return ans;
};

// tc -> O(n)
// sc -> O(n)