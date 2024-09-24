func trap(height []int) int {
    // doing with most optimal approach
    // water storage will be calculated at the current position
    l, r := 0, len(height) - 1
    lMax, rMax := 0, 0
    res := 0
    
    for l <= r {
        lVal := height[l]
        rVal := height[r]
        
        if lMax <= rMax {
            res += max(0, lMax - lVal)
            lMax = max(lVal, lMax)
            l++
        } else {
            res += max(0, rMax - rVal)
            rMax = max(rVal, rMax)
            r--
        }
    }
    
    return res
}
