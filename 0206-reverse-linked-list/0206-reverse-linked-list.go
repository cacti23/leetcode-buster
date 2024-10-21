/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    // check if linked list is empty of have one element
    if(head == nil || head.Next == nil) {
        return head
    } 
    
    cNode := head
    var pNode *ListNode // assignd nil rn
    
    for cNode != nil {
        temp := cNode.Next
        cNode.Next = pNode
        pNode = cNode
        cNode = temp
    }
    
    return pNode
}