/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
    let vMax = 0;
    let count = 0;
    const vSet = new Set(['a', 'e', 'i', 'o', 'u']);
    const l = s.length;
    
    // iterate over the array 
    for(let i = 0; i < l; i++) {
        if(i < k) {
            count += vSet.has(s[i]) ? 1 : 0;
        } else {
            count -= vSet.has(s[i - k]) ? 1: 0;
            count += vSet.has(s[i]) ? 1: 0;
        }
        
        vMax = Math.max(vMax, count);
        
        if(vMax === k) return k;
    }
    
    return vMax; 
};

// tc -> O(n)
// sc -> O(1)