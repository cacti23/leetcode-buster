/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let ls = s.length;
    let lt = t.length;
    
    if(ls > lt) return false;
    if(ls == 0 && lt === 0) return true;
    
    let i = 0, j = 0;
    
    for(let j = 0; j < lt; j++) {
        if(s[i] === t[j]) {
            i++;
        }
        
        if(i === ls) {
            return true;
        }
    }
    
    return false;
};

// tc -> O(n)
// sc -> O(1)