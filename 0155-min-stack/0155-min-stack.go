type MinStack struct {
    stack []int
    minStack []int
}


func Constructor() MinStack {
    return MinStack{
        stack:      []int{},
        minStack:   []int{},
    }
}


func (ms *MinStack) Push(val int)  {
    ms.stack = append(ms.stack, val)
    m := len(ms.minStack)
    
    if m == 0 || val <= ms.minStack[m - 1] {
        ms.minStack = append(ms.minStack, val)
    }
}


func (ms *MinStack) Pop()  {
    n := len(ms.stack)
    m := len(ms.minStack)
    
    if n == 0 {
        return
    }
    
    if ms.stack[n - 1] == ms.minStack[m - 1] {
        ms.stack = ms.stack[:n - 1]
        ms.minStack = ms.minStack[:m - 1]
    } else {
        ms.stack = ms.stack[:n - 1]
    }
}


func (ms *MinStack) Top() int {
    n := len(ms.stack)
    
    if n == 0 {
        return 0
    }
    
    return ms.stack[n - 1]
}


func (ms *MinStack) GetMin() int {
    n := len(ms.stack)
    m := len(ms.minStack)
    
    if n == 0 {
        return 0
    }
    
    return ms.minStack[m - 1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */