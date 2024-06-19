function compress(chars: string[]): number {
    // two pointer 
    let n = chars.length;
    if(n == 1) return 1;
    
    let i = 0, j = 1, s = '';
    
    while(i < n && j < n) {
        if(chars[i] === chars[j]) {
            j++;
        } else {
            let count = j - i;
            if(count > 1) {
                s += chars[i] + count;
            } else {
                s += chars[i];
            }
            i = j;
            j++;
        }
    }
    
    if(i < n) {
        let count = n - (i);
        if(count > 1) {
            s += chars[i] + count;
        } else {
            s += chars[i];
        }
    }
    
    let m = s.length;
    for(let k = 0; k < m; k++) {
        chars[k] = s[k];
    }
    
    return m;
};

// tc -> O(n)
// sc -> O(m)