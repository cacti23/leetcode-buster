func findMin(nums []int) int {
    res := nums[0]
    l, r := 0, len(nums) - 1
    
    for l <= r {
        m := (l + r) / 2
        
        // suppose nums[p] is 17 and nums[0] is 11 then smaller element will lie on right side of 17
        if nums[m] >= nums[0] {
            l = m + 1
        } else {
            if nums[m] < res {
                res = nums[m]
            }
            r = m - 1
        }
    }
    
    return res
}

// tc -> O(logn)
// sc -> O(1)