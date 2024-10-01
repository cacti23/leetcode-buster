func checkInclusion(s1 string, s2 string) bool {
    if len(s1) > len(s2){
        return false
    }
       
    // create hashmaps for string 1 and string 2
    hm1 := make(map[rune]int)
    hm2 := make(map[rune]int)
    
    // populate hm1
    // populate hm2 with intial window size of s1
    for i:= 0; i < len(s1); i++ {
        c1 := rune(s1[i])
        c2 := rune(s2[i])
        if _, ok := hm1[c1]; !ok {
            hm1[c1] = 1
        } else {
            hm1[c1]++
        }
        
        if _, ok := hm2[c2]; !ok {
            hm2[c2] = 1
        } else {
            hm2[c2]++
        }
    }

    // update hasmap for other chracter not present in window
    for i := 0; i < 26; i++ {
        key := rune('a' + i)
        if _, ok := hm1[key]; !ok {
            hm1[key] = 0
        }
        
        if _, ok := hm2[key]; !ok {
            hm2[key] = 0
        }
    }
    
    // create matches variable 
    // compare hashmaps
    matches := 0
    for k1, v1 := range hm1 {
        v2, exists := hm2[k1] 
        if exists && v1 == v2 {
            matches++
        }
    }
      
    j := 0
    // created a window now slide it 
    for i := len(s1); i < len(s2); i++ {
        if(matches == 26) {
            return true
        }
        
        // remove character from window
        rc := rune(s2[j])
        if hm2[rc] == hm1[rc] {
        matches--  // Counts were equal, now will be unequal
        }
        hm2[rc]--
        // update matches 
        if hm2[rc] == hm1[rc] {
            matches++
        }
        
        j++
        
        // add character to window
        ac := rune(s2[i])
        if hm2[ac] == hm1[ac] {
        matches--  // Counts were equal, now will be unequal
        }
        hm2[ac]++
        // update matches 
        if hm2[ac] == hm1[ac] {
            matches++
        }
    }
    
    return matches == 26   
}