func characterReplacement(s string, k int) int {
    hm := make(map[rune]int)
    res := 0
    j := 0
    maxF := 0
    
    for i, c := range s {
        if _, ok := hm[c]; ok {
            hm[c]++
        } else {
            hm[c] = 1
        }
        maxF = max(maxF, hm[c])
        
        // formula: current len of substring - max frequncy <= k
        if (i - j + 1) - maxF <= k {
            res = max(res, i - j + 1)
        } else {
            hm[rune(s[j])]--
            j++
        }
    }
    
    return res
}