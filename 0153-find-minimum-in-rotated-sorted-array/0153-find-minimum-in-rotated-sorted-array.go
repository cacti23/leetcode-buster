func findMin(nums []int) int {
    l, r := 0, len(nums) - 1
    res := math.MaxInt
    
    for l <= r {
        // identify the sorted half 
        m := (l + r) / 2
        mVal := nums[m]
        
        // check for sorted half
        if nums[l] <= mVal {
            // left half is sorted 
            // we will store the minimum value and move to next 
            if res > nums[l] {
                res = nums[l]
            }
            
            l = m + 1
        } else {
            // right half is sorted 
            // we will store the minimum and move to next 
            if res > mVal {
                res = mVal
            }
            
            r = m - 1
        }
    }
    
    return res
}