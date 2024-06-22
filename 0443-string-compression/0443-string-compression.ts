function compress(chars: string[]): number {
    let compressedArr: string[] = [];
    let countConsecutive = 0;
        
    for(let i = 0; i < chars.length; i++) {
        countConsecutive++;        
        if(i + 1 >= chars.length || chars[i] !== chars[i + 1]) {
            compressedArr.push(chars[i]);
            
            if(countConsecutive > 1) {
                let countStr = countConsecutive.toString();
                compressedArr.push(...countStr.split(''));
            }
            
            countConsecutive = 0;
        }
    }
    
    // copy back to the chars array 
    for(let i = 0; i < compressedArr.length; i++) {
        chars[i] = compressedArr[i];
    }

    return compressedArr.length;
};


// tc -> O(p) where p is the lenght of the original string
// sc -> O(p) worst case