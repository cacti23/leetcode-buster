func lengthOfLongestSubstring(s string) int {
    // when you are working with ascii dont use rune
    hm := make(map[byte]int)
    j := 0
    maxLen := 0
    n := len(s)
    
    for i := 0; i < n; i++  {
        c := s[i]
        if _, ok := hm[c]; ok {
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