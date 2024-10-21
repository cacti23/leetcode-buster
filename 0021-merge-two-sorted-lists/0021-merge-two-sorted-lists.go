/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    if list1 == nil && list2 == nil {
        return list1
    } 
    
    if list1 == nil {
        return list2
    }
    
    if list2 == nil {
        return list1
    }
    
    c1 := list1
    c2 := list2
    var res *ListNode // assigned as nil
    
    for c1 != nil && c2 != nil {
        if c1.Val <= c2.Val {
            if res == nil {
                res = c1
            } else {
                res.Next = c1
                res = res.Next
            }
            c1 = c1.Next
        } else {
            if res == nil {
                res = c2
            } else {
                res.Next = c2
                res = res.Next
            }
            c2 = c2.Next
        }
    }
    
    // remaining list1 elements
    if c1 != nil {
        if res == nil {
            res = c1
        } else {
            res.Next = c1
        }
    }
    
    // remaining list2 elements 
    if c2 != nil {
        if res == nil {
            res = c2
        } else {
            res.Next = c2
        }
    }
    
    if list1.Val <= list2.Val {
        return list1
    } else {
        return list2
    }
}