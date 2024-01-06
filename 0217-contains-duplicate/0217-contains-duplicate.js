/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    // using maps
    // in javacript maps are unordered
    const elementCounts = new Map();
    
    // count elements 
    nums.forEach(num => {
        elementCounts.set(num, (elementCounts.get(num) || 0) + 1);
    });
    
    return Array.from(elementCounts.values()).some((count) => count > 1);
};

// tc -> O(n* logn)
// sc -> O(n)
