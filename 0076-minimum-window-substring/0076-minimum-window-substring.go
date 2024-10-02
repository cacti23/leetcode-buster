func minWindow(s string, t string) string {
    l, r := 0, 0
    n, m := len(s), len(t)
    hmT := make(map[byte]int, m)
    hmS := make(map[byte]int, m)
    
    have, need := 0, 0
    res := ""
    resLen := n + 1  // Set initial result length to be larger than any possible window
    
    // Populate the hmT with counts of each character in t
    for i := 0; i < m; i++ {
        hmT[t[i]]++
    }
    
    need = len(hmT)
    
    for r < n {
        eCh := s[r]
        
        // Process the character at the right pointer
        if _, ok := hmT[eCh]; ok {
            hmS[eCh]++
            if hmS[eCh] == hmT[eCh] {
                have++
            }
        }
        
        // Once we've satisfied all characters in t
        for have == need {
            // Check if the current window is smaller
            if (r - l + 1) < resLen {
                res = s[l:r+1]
                resLen = r - l + 1
            }
            
            sCh := s[l]
            
            // Try to reduce the window size from the left
            if _, ok := hmT[sCh]; ok {
                hmS[sCh]--
                if hmS[sCh] < hmT[sCh] {
                    have--
                }
            }
            
            l++  // Move the left pointer
        }
        
        r++  // Move the right pointer
    }
    
    if resLen == n+1 {
        return ""
    }
    
    return res
}
