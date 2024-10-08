func search(nums []int, target int) int {
    // iterative 
    n := len(nums)
    left := 0
    right := n - 1
    
    for left <= right {
        mid := (left + right) / 2
        
        if nums[mid] == target {
            return mid
        } else if nums[mid] <= target {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    
    return -1
}