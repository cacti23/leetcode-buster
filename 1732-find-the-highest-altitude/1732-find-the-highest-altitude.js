/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function(gain) {
    // biker is starting from 0 altitude he/she needs to cover n points ahead for which the array is given
    // ex: [-5,1,5,0,-7]
    // suppose the biker goes to index 0 of given array he move from 0 altitude to -5 then he move to index 1 which is 1 so he is currently at -4 altitude which is obtained by adding -5 and 1
    
    // we are using curr to not use extra space
    let l = gain.length, ans = 0, curr = 0;
    
    // populate current array with prefix sum 
    for(let i = 0; i < l; i++) {
        gain[i] = curr + gain[i];
        curr = gain[i];
    } 
    
    // find the max value of the array 
    for(let i = 0; i < l; i++) {
        ans = Math.max(ans, gain[i]);
    }
    
    return ans;
};

// draw this solution once
// tc -> O(n)
// sc -> O(1)