/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    nodeArr := make([]int, 0)
    // brute force
    // add all elements to array sort array then create sorted linked list
    for _, list := range lists {
        curr := list 
        for curr != nil {
            nodeArr = append(nodeArr, curr.Val)
            curr = curr.Next
        }
    }
    
    sort.Ints(nodeArr)
    
    dummy := &ListNode{}
    curr := dummy
    for _, v := range nodeArr {
        temp := &ListNode{Val: v, Next: nil} 
        curr.Next = temp
        curr = curr.Next
    }
    
    return dummy.Next
}