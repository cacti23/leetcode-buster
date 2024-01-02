/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findMatrix = function(nums) {

    let countMap = new Map();
    
    // populate the map
    for(const n of nums) {
        countMap.set(n, (countMap.get(n) || 0) + 1);
    }
    
    let ans = [];
    while(countMap.size > 0) {
        let temp = [];
        let toErase = [];
        for(let[ele, freq] of countMap) {
            temp.push(ele);
            freq--;
            if(freq == 0) {
                toErase.push(ele);
            }
            countMap.set(ele, freq);
        }
        ans.push(temp);
        for(let i of toErase) {
            countMap.delete(i);
        }
    }
    
    return ans;
};

// tc -> O(n*n)
// sc -> O(n)
// number of rows will  be decided on the basis on most repeating number  