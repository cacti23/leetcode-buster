/**
 * @param {string} sentence
 * @return {boolean}
 */
var checkIfPangram = function(str) {
    const arr = new Array(26).fill(false);
    
    for(let i = 0; i < str.length; i++) {
        let index;
        const charCode = str.charCodeAt(i);
        
        if(charCode >= 'A'.charCodeAt(0) && charCode <="Z".charCodeAt(0)) {
            index = charCode - 'A'.charCodeAt(0);
        } else if(charCode >= 'a'.charCodeAt(0) && charCode <= 'z'.charCodeAt(0)) {
            index = charCode - 'a'.charCodeAt(0);
        } else {
            continue;
        }
        
        if(!arr[index]) arr[index] = true;
    }
    
    
    for(let i = 0; i < 26; i++) {
        if(!arr[i]) return false;
    }
    
    return true;
};