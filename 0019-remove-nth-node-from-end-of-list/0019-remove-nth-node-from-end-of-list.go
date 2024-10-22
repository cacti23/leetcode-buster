/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // remove nth from end means remove len - n + 1 from front
    cNode := head
    count := 0
    var temp *ListNode
    
    for cNode != nil {
        count++
        cNode = cNode.Next
    }
    
    // set the new value m which will be just one before the node to be removed
    m := count - n
    cNode = head
    
    // if m is zero means the first head needs to be removed
    if m == 0 {
        temp = cNode.Next
        cNode.Next = nil
        return temp
    }
    
    // get to one node before the one that is to be removed
    for m > 1 {
        cNode = cNode.Next
        m--;
    }
    
    // remove operation
    temp = cNode.Next
    cNode.Next = temp.Next
    temp.Next = nil
    
    return head
}