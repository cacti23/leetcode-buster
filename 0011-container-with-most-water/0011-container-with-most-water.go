func maxArea(height []int) int {
    n := len(height)
    l := 0
    r := n - 1
    res := 0
    tArea := 0
    
    for l < r {
        // calculate the current area 
        mHeight := min(height[l], height[r])
        tArea = mHeight * (r - l)
        
        if tArea > res {
            res = tArea
        }
        
        // to maximize area we need to update l and r respectively
        if(height[l] > height[r]) {
            r--
        } else {
            l++
        }
    }
    
    return res
}