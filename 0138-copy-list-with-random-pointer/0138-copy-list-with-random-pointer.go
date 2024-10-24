/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    if head == nil {
        return head
    }
    
    c1 := head
    var t1 *Node
    
    // first pass: add new nodes next to the old nodes
    for c1 != nil {        
        t1 = c1.Next
        c1.Next = &Node{Val: c1.Val}
        c1.Next.Next = t1
        c1 = t1
    }
    
    c1 = head
    c2 := head.Next
    // second pass: set the random pointer correctly
    for c1 != nil {
        if c1.Random == nil {
            c2.Random = nil
        } else {
            c2.Random = c1.Random.Next
        }
        
        c1 = c2.Next
        if c1 != nil {
            c2 = c1.Next
        }
    }
    
    // third pass: separate the old nodes from new
    c1 = head
    c2 = head.Next
    res := head.Next
    
    for c1 != nil { 
        c1.Next = c2.Next
        if c2.Next == nil {
            c2.Next = nil
        } else {
            c2.Next = c2.Next.Next
        }
        
        c1 = c1.Next
        c2 = c2.Next
    }
    
    return res
    
}