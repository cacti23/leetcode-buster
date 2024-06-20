function compress(chars: string[]): number {
    let compressedString = '';
    let countConsecutive = 0;
    
    for(let i = 0; i < chars.length; i++) {
        countConsecutive++;
        
        if(i + 1 >= chars.length ||chars[i] !== chars[i + 1]) {
            if(countConsecutive > 1) compressedString += chars[i] + countConsecutive;
            else compressedString += chars[i];
            countConsecutive = 0;
        }
        

    }
    
    for(let i = 0; i < compressedString.length; i++) {
        chars[i] = compressedString[i];
    }
    
    return compressedString.length;
};

