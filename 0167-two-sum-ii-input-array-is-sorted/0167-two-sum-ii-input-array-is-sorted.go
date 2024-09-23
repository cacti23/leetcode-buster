func twoSum(nums []int, t int) []int {
    i := 0
    j := len(nums) - 1
    
    for i < j {
        s := nums[i] + nums[j]
        
        if s == t {
            return []int{i + 1, j + 1};
        } else if s > t {
            j--
        } else {
            i++
        }
    }
    
    return nil
}