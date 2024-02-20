function removeStars(s: string): string {
    const l = s.length;
    const arr = s.split('');
    let j = 0;     
    let char = '';
    for(let i = 0; i < l; i++) {
        char = s[i];
        if(char === '*') {
            j--;
        } else {
            arr[j++] = s[i];
        }
    }
    
    return arr.slice(0, j).join('');
};

// tc -> O(n) + O(n) + O(n)
// sc -> O(1)