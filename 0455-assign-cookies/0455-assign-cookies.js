/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    // first sorting array in ascending order so that our two pointer works
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
        
    // using two pointers
    let i = 0, j = 0;
    
    while(i < g.length) {
        // find the cookie that can satisfy the child
        while(j < s.length && g[i] > s[j]) {
            j++;
        }
        
        // after finding the correct cookie
        if(j >= s.length) break;
        
        i++;
        j++;
    }
    
    return i;
};


// tc -> O(nlogn + mlogn + n) => O(nlogn)
// sc -> O(1)