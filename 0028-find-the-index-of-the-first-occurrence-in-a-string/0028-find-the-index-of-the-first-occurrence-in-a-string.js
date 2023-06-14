/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle === "") return -1;
    
    const n = haystack.length;
    const m = needle.length;
    
    for(let i = 0; i <= n - m; i++) {
        for(let j = 0; j < m; j++) {
            if(haystack[i + j] !== needle[j]) break;
            
            if(j === m - 1) return i;
        }
    }
    
    return -1;
};