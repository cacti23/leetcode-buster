/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {
    const n = grid.length;
    const m = new Map();
    let ans = 0;
    
    // store each row into the map 
    for(let i = 0; i < n; i++) {
        let rowRef = grid[i].join(',')
        if(m.has(rowRef)) {
            m.set(rowRef, m.get(rowRef) + 1);
        } else {
            m.set(rowRef, 1);
        }
    }
    
    // create colRef & check into map if it exists or not
    for(let i = 0; i < n; i++) {
        let col = [];
        for(let j = 0; j < n; j++) {
            col.push(grid[j][i]);
        }
        
        let colRef = col.join(',');
        
        if(m.has(colRef)) {
            ans += m.get(colRef);
        }
    }
    
    return ans;   
};

// tc -> O(n*n) + O(n*n)
// sc -> O(n) + O(n)

