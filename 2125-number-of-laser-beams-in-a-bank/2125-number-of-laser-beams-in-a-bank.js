/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function(bank) {
    let ans = 0, prev = 0;
    for(let i = 0; i < bank.length; i++) {
        // count the number of one in the row
        let oneCount = (bank[i].match(/1/g) || []).length;
        
        if(oneCount === 0) continue;
        
        ans += prev * oneCount;
        prev = oneCount;
    }
    
    return ans;
};

// tc -> O(n*m)
// sc -> O(1)