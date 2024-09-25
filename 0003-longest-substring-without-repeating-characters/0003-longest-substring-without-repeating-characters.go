func lengthOfLongestSubstring(s string) int {
    // can be done using two for loops with hashmap but that is not optimal solution 
    // whenever something related to substring comes plese think about two pointers and sliding window
    // hash map to store the character and index
    hm := make(map[rune]int)
    j := 0
    maxLen := 0
    
    for i, c := range s {
        if _, ok := hm[c]; ok {
            // update the index if the j is less than or equal to that for case abba
            if(j <= hm[c]) {
                j = hm[c] + 1
            }
            
        } 
        
        hm[c] = i
        maxLen = max(maxLen, i - j + 1)
    }
    
    return maxLen   
}

// tc -> O(n)
// sc -> O(1)