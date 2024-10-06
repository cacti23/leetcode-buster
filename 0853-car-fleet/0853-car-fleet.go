func carFleet(target int, position []int, speed []int) int {
    n := len(position)
    
    stack := make([]float32, 0, n)
    pair := make([]carInfo, 0, n)
    
    for i, _ := range position {
        pair = append(pair, carInfo{p:position[i], s: speed[i]})
    }
    
    sort.Slice(pair, func(i, j int) bool {
        return pair[i].p < pair[j].p
    })
    
    for i := n - 1; i >= 0; i-- {
        t := float32(target - pair[i].p)/float32(pair[i].s)
        stack = append(stack, t)
        
        m := len(stack)
        
        if m >= 2 && stack[m - 1] <= stack[m - 2] {
            stack = stack[:m - 1]
        }
    }
    
    return len(stack)
    
}

type carInfo struct {
    p int
    s int
}