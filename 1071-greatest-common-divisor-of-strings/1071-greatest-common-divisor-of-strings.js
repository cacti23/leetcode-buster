/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */

/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    // if concat the two string prodcues different results when the order is different means they don't share a common repeating pattern.
    if((str1 + str2) !== (str2 + str1)) return '';
    
    // After making sure the pattern is there now this question becomes a simple gcd one
    let l1 = str1.length, l2 = str2.length;
    
    const index = gcd(l1, l2);
    
    return str1.slice(0, index);
};

var gcd = function(a, b) {
    while(a > 0 && b > 0) {
        if(a > b) a = a % b;
        else b = b % a; 
    }
    
    if(a == 0) return b;
    return a;
}

// tc -> O(log(min(m, n)))
// sc -> O(1)