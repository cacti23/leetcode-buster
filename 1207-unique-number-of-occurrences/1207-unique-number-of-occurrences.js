/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    let freq = new Map();
    
    // populate the frequency map
    for(let num of arr) {
        if(freq.has((num))) {
            freq.set(num, (freq.get(num) + 1));
        } else {
            freq.set(num, 1);
        }
    }
    
    // create a set and add map key values to it
    const mySet = new Set();
    for(let val of freq.values()) {
        if(mySet.has(val)) return false;
        mySet.add(val);
    }
    
    return true;
};

// tip of the day: javacript object keys are always string or symbols. If you provide integers js will automatically convert it into string

// tc -> O(n)
// sc -> O(n)