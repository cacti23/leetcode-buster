type StackNode struct {
    data int
    min int // minimum value at this point in the stack
    next *StackNode
}

type MinStack struct {
    top *StackNode
}

func Constructor() MinStack {
    return MinStack{
        top: nil,
    }
}


func (ms *MinStack) Push(val int)  {
    if ms.top == nil {
        ms.top = &StackNode{
            data: val, 
            min: val,
            next: nil,
        }
    } else {
        newMin := min(val, ms.top.min)
        newNode := &StackNode{
            data: val, 
            min: newMin, 
            next: ms.top, // new node will be new top and next will pooint to old top
        }
        
        ms.top = newNode
    }
}


func (ms *MinStack) Pop()  {
    if ms.top != nil {
        ms.top = ms.top.next
        // no need to delete the node cuz in golang once the refernce is removed it will be automatically get removed
    }
}


func (ms *MinStack) Top() int {
    if ms.top != nil {
        return ms.top.data
    }
    
    return 0
}


func (ms *MinStack) GetMin() int {
    if ms.top != nil {
        return ms.top.min
    }
    
    return 0
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */