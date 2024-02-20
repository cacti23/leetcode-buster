function removeStars(s: string): string {
    const l = s.length;
    let ans: string[] = [];
    
    for(let i = 0; i < l; i++) {
        let char = s[i];
        if(char === '*') {
            ans.pop();
        } else {
            ans.push(char);
        }
    }
    
    return ans.join('');
};

// tc -> O(n)
// sc -> O(1)
