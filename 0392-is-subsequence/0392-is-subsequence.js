/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let ls = s.length;
    let lt = t.length;
    
    if(ls > lt) return false;
    
    let i = 0;
    
    for(let j = 0; j < lt; j++) {
        if(s[i] === t[j]) {
            i++;
        }
        
        if(i === ls) {
            return true;
        }
    }
    
    
    // in case of both of string lenght is zero
    return i === ls;
};

// tc -> O(n)
// sc -> O(1)