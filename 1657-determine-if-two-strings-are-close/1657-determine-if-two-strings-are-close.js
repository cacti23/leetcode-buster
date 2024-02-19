/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    // condition1 --> length should be same
    let l1 = word1.length,
        l2 = word2.length;
        
    if(l1 !== l2) return false;
    const freq1 = new Array(26).fill(0);
    const freq2 = new Array(26).fill(0);
        
    // populate freq1
    for(let i = 0; i < l1; i++) {
        freq1[word1.charCodeAt(i) - 'a'.charCodeAt()]++;
    }
    
    // populate freq2
    // condition 2 -> there are same element in both strings
    for(let i = 0; i < l2; i++) {
        if(freq1[word2.charCodeAt(i) - 'a'.charCodeAt()] == 0) return false;
        freq2[word2.charCodeAt(i) - 'a'.charCodeAt()]++;
    }
    
    // condition 3 -> each freq of char should have the equal size of char in other string
    freq1.sort((a, b) => a - b);
    freq2.sort((a, b) => a - b);
    
    for(let i = 0; i < 26; i++) {
        if(freq1[i] !== freq2[i]) return false;
    }
    
    return true;
};

// tc -> O(n) , since we are sorting fixed length arrays
// sc -> O(1)