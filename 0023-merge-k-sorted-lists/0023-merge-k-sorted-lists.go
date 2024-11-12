/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeList(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    curr := dummy
    
    for l1 != nil && l2 != nil {
        if l1.Val <= l2.Val {
            curr.Next = l1
            l1 = l1.Next
        } else {
            curr.Next = l2
            l2 = l2.Next
        }
        
        curr = curr.Next
    }
    
    // remaining elements for l1 and l2
    if l1 != nil {
        curr.Next = l1
    }
    
    if l2 != nil {
        curr.Next = l2
    }
    
    return dummy.Next
}

func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 {
        return nil
    }
    
    for i := 1; i < len(lists); i++ {
        lists[i] = mergeList(lists[i - 1], lists[i])
    }
    
    return lists[len(lists) - 1]
}