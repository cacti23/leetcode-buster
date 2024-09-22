func productExceptSelf(nums []int) []int {
    res := make([]int, len(nums))
    
    // calculate prefix
    prefix := 1
    for i, v := range nums {
        res[i] = prefix
        prefix *= v
    }
    
    // calculate postfix 
    postfix := 1
    for i := len(nums) - 1; i >= 0; i-- {
        res[i] *= postfix
        postfix *= nums[i]
    }
    
    return res
}