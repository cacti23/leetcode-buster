func findDuplicate(nums []int) int {
    for _, num := range nums {
        // map nums from 1 to n range to 0 to n - 1
        idx := abs(num) - 1
        // if it is already marked negative then that is the number 
        if nums[idx] < 0 {
            // this index value is negative means it was already marked negative
            return abs(num)
        } 

        nums[idx] *= -1
    }

    return -1
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    
    return num
}