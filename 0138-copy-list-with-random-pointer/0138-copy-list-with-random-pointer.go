/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(h *Node) *Node {
    if h == nil {
        return h
    }
    
    // map to hold the original node nd it's copy
    nMap := make(map[*Node]*Node)
    
    // create the new head noded and start the loop
    current := h
    copyHead := &Node{Val: current.Val}
    prevCopy := copyHead
    nMap[current] = copyHead
    
    // first pass create the new linked list with only next pointer
    for current = current.Next; current != nil; current = current.Next {
        newNode := &Node{Val: current.Val}
        nMap[current] = newNode
        prevCopy.Next = newNode
        prevCopy = newNode
    }
    
    // second pass use map to get the copy on random pointer
    current = h
    copyCurrent := copyHead
    
    for current != nil {
        copyCurrent.Random = nMap[current.Random]
        
        current = current.Next
        copyCurrent = copyCurrent.Next
    }
    
    return copyHead
}

// tc -> O(n) + O(n)
// sc -> O(n)