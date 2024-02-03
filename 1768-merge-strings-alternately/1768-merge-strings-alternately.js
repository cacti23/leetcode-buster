/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let i = 0, j = 0;
    let l1 = word1.length;
    let l2 = word2.length;
    let s = '';
    
    while(i < l1 && j < l2) {
        s += word1[i++] + word2[j++];
    }
    
    while(i < l1) {
        s += word1[i++];
    }
    
    while(j < l2) {
        s += word2[j++];
    }
    
    return s;
};