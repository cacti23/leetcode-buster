func topKFrequent(nums []int, k int) []int {    
    countMap := make(map[int]int)
    countSlice := make([][]int, len(nums) + 1)
    
    // update hashmap
    for _, v := range nums {
        if _, ok := countMap[v]; ok {
            countMap[v] = countMap[v] + 1
        } else {
            countMap[v] = 1
        }
    }
    
    // copy hashmap to slice
    // mapping index to frequecy of elements
    for num, count := range countMap {
        countSlice[count] = append(countSlice[count], num)
    }
    
    res := make([]int, 0, k);
    // find the k top element 
    for i := len(countSlice) - 1; i > 0; i-- {
        res = append(res, countSlice[i]...)
		if len(res) == k {
			return res
		}
    }
    
    return res
}

