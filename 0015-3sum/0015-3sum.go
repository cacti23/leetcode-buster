func threeSum(nums []int) [][]int {
    n := len(nums)
    res := make([][]int, 0, n)
    
    // sort nums
    // the reason for sorting is to elimiate the duplicate 
    slices.Sort(nums)
    
    // iterate over the loop
    for i1 := 0; i1 < n - 2; i1++ {
        // use two pointer like we did in two sum 2 with sorted arrays 
        // logic to avoid duplication
        // the reason to skip is for this exact value we would have already calculated the triplet
        if i1 > 0 && nums[i1 - 1] == nums[i1] {
            continue
        }
        
        i2 := i1 + 1
        i3 := n - 1
        
        for i2 < i3 {
            s := nums[i1] + nums[i2] + nums[i3] 
            
            if s == 0 {
                res = append(res, []int{nums[i1], nums[i2], nums[i3]})
                i2++
                i3--
                // skip duplicates from left 
                for i2 < i3 && nums[i2 - 1] == nums[i2] {
                    i2++
                }
                
                // skip duplicates from right 
                // problem occured here
                for i2 < i3 && nums[i3 + 1] == nums[i3] {
                    i3--
                }
            } else if s < 0 {
                i2++
            } else {
                i3--
            }
        }
    }
    
    return res
}

// tc -> O(nlogn) + O(n^2)
// sc -> O(n) for sorting