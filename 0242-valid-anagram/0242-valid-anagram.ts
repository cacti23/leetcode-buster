function isAnagram(s: string, t: string): boolean {
    let n = s.length;
    let m = t.length;
    if(n !== m) return false;
    
    const sortS = s.split('').sort().join('');
    const sortT = t.split('').sort().join('');
    
    return sortS === sortT;
};

// tc -> O(nlogn)
// sc -> O(n)