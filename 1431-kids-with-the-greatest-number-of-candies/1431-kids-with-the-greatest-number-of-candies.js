/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    const maxCandies = Math.max(...candies);
    
    const result = candies.map((candy) => {
        return (candy + extraCandies) >= maxCandies;
    });
    
    return result;
};

// tc -> O(n)
// sc -> O(1)