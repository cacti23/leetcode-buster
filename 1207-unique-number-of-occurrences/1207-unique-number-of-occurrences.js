/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    // value of array ranges from -1000 to 1000 so we can say max 2001 elements
    let m = new Array(2001).fill(0);
    // array to store the frequency of frequency in the above array
    let n = new Array(1001).fill(0);
    
    // count the occurrence of each number in the array 
    for(let num of arr) {
        m[num + 1000]++;
    }
    
    // since we have the freq which cannot be greater than 1000 at this point
    for(let i = 1; i < 2001; i++) {
        if(m[i] > 0) {
            let count = m[i];
            // if the count which is frequncy of the element is greater than on means this freq is being repeated
            if(n[count] >= 1) return false;
            n[count]++;
        }
    }
    
    return true;
    
};

// tip of the day: javacript object keys are always string or symbols. If you provide integers js will automatically convert it into string

// tc -> O(n)
// sc -> O(1)