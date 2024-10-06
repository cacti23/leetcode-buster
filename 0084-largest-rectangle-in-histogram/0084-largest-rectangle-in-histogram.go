func largestRectangleArea(heights []int) int {
    st := []Pair{}
    mArea := 0
    
    // traverse through the whole array 
    for i, h := range heights {
        // if the top of stack is greater than the curret value means the current value will be next smaller element and the values of stack that follow this condition becomes eligible to calculate area 
        start := i
        for len(st) != 0 && h < st[len(st) - 1].h {
            ind := st[len(st) - 1].i
            hei := st[len(st) - 1].h
            mArea = max(mArea, hei * (i - ind)) 
            st = st[:len(st) - 1]
            start = ind // keep the track of the correct position where a rectangle of the current height should start when previous tall bars are popped from stack
            // means the index before which small element is present 
            // it becomes easy to calculate when this traversal is complete
        }
        
        st = append(st, Pair{start, h})
    }
    
    // Some element will be there in stack after the traversal 
    for _, p := range st {
        mArea = max(mArea, p.h * (len(heights) - p.i))
    }
    
    return mArea
}

type Pair struct {
    i int
    h int
}