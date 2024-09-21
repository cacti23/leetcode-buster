func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    var freq [26]int
    
    for idx, _ := range s {
        freq[s[idx] - 'a']++
        freq[t[idx] - 'a']--
    }
    
    for idx, _ := range freq {
        if(freq[idx] != 0) {
            return false
        }
    }
    
    return true
}