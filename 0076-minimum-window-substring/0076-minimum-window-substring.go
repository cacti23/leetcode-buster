func minWindow(s string, t string) string {
    l, r := 0, 0
    n, m := len(s), len(t)
    // using byte cuz of ascii
    hmT := make(map[byte]int, m)
    hmS := make(map[byte]int, m) 
    have, need := 0, 0
    res := ""
    resLen := n + 1 // cuz we are trying to find the minimum length
    
    // update hmT
    for i := range t {
        hmT[t[i]]++
    }
    
    need = len(hmT)
    
    for r < n {
        eCh := s[r]
        
        // update the hmS 
        if _, ok := hmT[eCh]; ok {
            hmS[eCh]++
            if hmS[eCh] == hmT[eCh] {
                have++
            }
        }
        
        // if we have all chars reduce the length
        for have == need {
            if r - l + 1 < resLen {
                res = s[l:r+1]
                resLen = r - l + 1
            }
            
            sCh := s[l]
            
            if _, ok := hmS[sCh]; ok {
                hmS[sCh]--
                if hmS[sCh] < hmT[sCh] {
                    have--
                }
            }
            
            l++
        }
        r++
    }
    
    if resLen == n + 1 {
        return ""
    }
    
    return res
}