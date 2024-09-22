func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    
    for i1, num := range nums {
        if i2, found := m[target - num]; found {
            return []int{i1, i2}
        }
        
        m[num] = i1;
    }
    
    return nil
}