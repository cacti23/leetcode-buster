function rotateString(s: string, goal: string): boolean {
    if(s.length !== goal.length) return false;
    
    let n = s.length;
    
    // find on string inside another
    
    // outer loop for source string
    for(let i = 0; i < n; i++) {
        let found = true;
        // inner loop for goal string
        for(let j = 0; j < n; j++) {
            if(s[(i + j) % n] !== goal[j]) {
                found = false;
                break;
            }
        }
        
        // after inner loop gets completed then check 
        if(found) {
            return true;
        }
    }
    
    return false
};
// we did not double the string hence space complexity is reduced

// tc -> O(n*m) which will be O(n^2)
// sc -> O(1)