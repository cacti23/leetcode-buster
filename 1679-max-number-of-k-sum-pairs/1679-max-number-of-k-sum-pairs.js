/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function(nums, k) {
    const l = nums.length;
    nums.sort((a, b) => a - b);
    
    let count = 0, i = 0, j = l - 1;
    
    while(i < j) {
        let sum = nums[i] + nums[j];
        if(sum == k) {
            count++;
            i++;
            j--;
        }
        else if(sum < k) i++;
        else j--;
    }
    
    return count;
};

// tc -> O(nlogn) + O(n) = O(nlogn) 
// sc -> O(1)