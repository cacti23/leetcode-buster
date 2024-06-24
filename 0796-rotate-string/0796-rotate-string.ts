function rotateString(s: string, goal: string): boolean {
    if(s.length !== goal.length) return false;
    
    let n = s.length;
    let m = n * 2;
    
    let con = s + s;
    
    // two pointers 
    let i = 0, j = 0;
    
    while(i < m) {
        if(con[i] === goal[j]) {
            i++;
            j++;
            if(j === n) return true;
        } else {
            if(j != 0) {
                i = i - j + 1;
                j = 0;
            } // if the string are of same length but content is different "abcde" "abced" also they matched the another substring pattern not the one which is actually needed to be matched
            else i++;
        }
    }
    
    return false;
};

// tc -> O(2n) -> O(n)
// sc -> O(n)