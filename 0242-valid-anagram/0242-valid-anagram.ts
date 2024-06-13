function isAnagram(s: string, t: string): boolean {
    let n = s.length;
    let m = t.length;
    if(n !== m) return false;
    
    const freq = new Array<number>(26).fill(0);
    
    for(let i = 0; i < n; i++) {
        freq[s.charCodeAt(i) - 97]++;
    }
    
    // now the frequency array setup is done
    for(let i = 0; i < m; i++) {
        let ind = t.charCodeAt(i) - 97;
        if(freq[ind] <= 0) return false;
        freq[ind]--;
    }
    
    return true;
};

// tc -> O(n)
// sc -> O(1)