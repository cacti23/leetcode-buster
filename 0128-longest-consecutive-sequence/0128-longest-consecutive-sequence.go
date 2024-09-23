func longestConsecutive(nums []int) int {
    hashMap := make(map[int]bool)
    
    // update the hashmap 
    for _, v := range nums {
        hashMap[v] = true
    }
    
    res := 0
    
    // iterate the loop and find the sequence
    for _, v := range nums {
        count := 0;
        // find if this is the sequence starting
        if _, ok := hashMap[v - 1]; ok {
            continue
        } else {
            // if it is a starting sequnce then count the seq
            key := v
            for {
                _, ok := hashMap[key]
                
                if !ok {
                    break
                }
                
                count++
                key++
            }
            
            if count > res {
                res = count
            }
        }
    }
    
    return res
}