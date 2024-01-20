/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    // store the maximum length 
    const maxLength = Math.max(word1.length, word2.length);
    
    return Array.from({length: maxLength}).reduce((acc, _, i)=> acc += (word1[i] || '') + (word2[i] || ''), '');
};

// tc -> O(max(n, m))
// sc -> O(n + m)