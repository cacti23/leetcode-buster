/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(fb, n) {
    const l = fb.length;
    
    if(n === 0) return true;
    
    if(fb.length === 1) {
        if(fb[0] === 0) n--;
        
        if(n == 0) return true;
        return false;        
    } 
    
    for(let i = 0; i < l; i++) {
        // can plant a flower 
        if(fb[i - 1] === undefined && fb[i + 1] === 0 && fb[i] === 0) {
            n--;
            fb[i] = 1;
        } else if (fb[i - 1] === 0 && fb[i + 1] === 0 && fb[i] === 0) {
            n--;
            fb[i] = 1;
        } else if(fb[i - 1] === 0 && fb[i + 1] === undefined && fb[i] === 0) {
            n--;
            fb[i] = 1;
        }
        
        
        if(n == 0) return true;
    }
    return false;
};

// tc -> O(n)
// sc -> O(1)