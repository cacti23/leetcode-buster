func maxSlidingWindow(nums []int, k int) []int {
    res := make([]int, 0)
    // doubly ended queue --> decreasing order of chars in indices 
    q := make([]int, 0)
    l, r := 0, 0
    n := len(nums)
    
    for r < n {
        // find the correct place for adding new element in queue
        for len(q) > 0 && nums[q[len(q) - 1]] < nums[r] {
            q = q[:len(q) - 1]
        }
        // add element index to the correct place
        q = append(q, r)
        
        // for non-incresing array
        if l > q[0] {
            // remove the top head 
            q = q[1:]
        }
        
        if r + 1 >= k {
            res = append(res, nums[q[0]])
            l++
        }
        
        r++
    }
    return res
}