func longestConsecutive(nums []int) int {
    hashMap := make(map[int]bool)
    
    // update the hashmap 
    for _, v := range nums {
        hashMap[v] = true
    }
    
    res := 0
    
    // iterate the loop and find the seq
    for _, v := range nums {
        // if this is the starting of the seq
        if !hashMap[v - 1] {
            count := 1
            key := v + 1
            
            for hashMap[key] {
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