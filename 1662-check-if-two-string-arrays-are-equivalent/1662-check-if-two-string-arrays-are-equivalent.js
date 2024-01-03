/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
var arrayStringsAreEqual = function(word1, word2) {
    // index of words
    let w1 = 0, w2 = 0;
    // index of char
    let i = 0, j = 0;
    
    while (w1 < word1.length && w2 < word2.length) {
        // if they are not equal
        if(word1[w1][i] != word2[w2][j]) return false;
        
        i++;
        j++;
        if(i == word1[w1].length) {
            w1++;
            i = 0;
        }
        
        if(j == word2[w2].length) {
            w2++;
            j = 0;
        }
    }
    
    if(w1 != word1.length || w2 != word2.length) return false;
    
    return true;
};

// tc -> O(n + m)
// sc -> O(1)