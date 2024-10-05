type Pair struct{
    ind int
    val int
}

func dailyTemperatures(temp []int) []int {
    res := make([]int, len(temp))
    st := []Pair{}
    
    for i, v := range temp {
        for len(st) > 0 && st[len(st) - 1].val < v {
            // update he index in results array 
            top := st[len(st) - 1]
            res[top.ind] = i - top.ind
            st = st[:len(st) - 1]
        }
        
        st = append(st, Pair{ind: i, val: v})
    }
    
    return res
}