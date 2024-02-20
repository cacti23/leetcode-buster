function removeStars(s: string): string {
    const l = s.length;
    let ans = '';
    
    for(let i = 0; i < l; i++) {
        let char = s[i];
        if(char === '*') {
            ans = ans.slice(0, ans.length - 1);
        } else {
            ans += char;
        }
    }
    
    return ans;
};

// tc -> O(n)
// sc -> O(1)
