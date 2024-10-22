/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    // calculat the length of given linked list 
    cNode := head 
    count := 0
    
    for cNode != nil {
        count++
        cNode = cNode.Next
    }
    
    if count < 3 {
        return
    }
    
    // get the value from where the list needs to be reversed
    var nHead1, nHead2 *ListNode
    
    //pivot
    piv := (count + 1) / 2
    cNode = head
    
    for i := 0; i < piv; i++ {
        // last node Next if first list needs to be set nil
        if i == piv - 1 {
            temp := cNode.Next
            cNode.Next = nil
            cNode = temp
        } else {
            cNode = cNode.Next
        }

    }
    
    nHead1 = head
    // reverse the second list
    nHead2 = reverseList(cNode)
    
    // nHead1 list will always be longer than nHead2
    for nHead2 != nil {
        t1 := nHead1
        t2 := nHead2
        nHead1 = nHead1.Next
        nHead2 = nHead2.Next
        t1.Next = t2
        t2.Next = nHead1
    }
}

func reverseList(head *ListNode) *ListNode {
    if(head == nil || head.Next == nil) {
        return head
    } 
    
    cNode := head
    var pNode *ListNode
    
    for cNode != nil {
        temp := cNode.Next
        cNode.Next = pNode
        pNode = cNode
        cNode = temp
    }
    
    return pNode
}