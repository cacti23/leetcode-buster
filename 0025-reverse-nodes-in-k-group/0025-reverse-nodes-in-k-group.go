/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {    
    dHead, curr, i := head, head, 0
    
    if k == 1 {
        return head
    }

    for curr != nil {
        i++
        if i % k == 0 {
            // for first reversal 
            if dHead == head {
                reverse(dHead, curr)
                head = curr
                curr = dHead.Next
            } else {
                reverse(dHead.Next, curr)
                tmp := curr
                tmp2 := dHead.Next
                curr = dHead.Next.Next
                dHead.Next = tmp
                dHead = tmp2
            }
        } else {
            curr = curr.Next
        }
    }
    
    return head
}

func reverse(start *ListNode, end *ListNode) {
    // next node after group
    node := end.Next
    dummy := &ListNode{Next: start}
    prev := dummy
    
    for start != node {
        tmp := start.Next
        start.Next = prev
        prev = start
        start = tmp
        
    }
    
    dummy.Next.Next = node
    dummy.Next = nil
}