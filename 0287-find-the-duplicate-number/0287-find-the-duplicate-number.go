func findDuplicate(nums []int) int {
    // bitwise solution
    // images 32 bits we will iterate over each bit
    n := len(nums)
    res := 0
    
    for b := 0; b < 32; b++ {
        x, y := 0, 0
        mask := 1 << b
        
        // count the set bit at this bit position in array
        for _, num := range nums {
            if num & mask != 0 {
                x++
            }
        }
        
        // count the set bit at this bit position in 1 to n range 
        for i := 1; i < n; i++ {
            if i & mask != 0 {
                y++
            }
        }
        
        if x > y {
            // we are doing this operation cuz imagine if the number is 2 then we can return res but if the number is 15 then we need to add mask to res 
            res |= mask
        }
    }
    
    return res
}