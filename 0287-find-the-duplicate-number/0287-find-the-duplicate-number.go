func findDuplicate(nums []int) int {
    slow, fast := 0, 0
    
    // find the loop
    // set the value of slow
    for {
        slow = nums[slow]
        fast = nums[nums[fast]]
        
        if slow == fast {
            break
        }
    }
    
    // as slow and fast method they will coincide if you start from zero
    slow2 := 0
    for {
        slow = nums[slow]
        slow2 = nums[slow2]
        
        if slow == slow2 {
            return slow
        }
    }
    
    return -1
}