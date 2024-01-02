/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findMatrix = function(nums) {
    const freq = new Array(nums.length + 1).fill(0);
    const ans = [];
    
    for(const n of nums) {
        // if the freq of an element is greater than the size of ans than another subarray is needed to be added
        if(freq[n] >= ans.length) {
            ans.push([]);
        }
        
        ans[freq[n]].push(n);
        freq[n]++;
    }
    
    return ans;
};

// tc -> O(n)
// sc -> O(n)
// number of rows will  be decided on the basis on most repeating number  