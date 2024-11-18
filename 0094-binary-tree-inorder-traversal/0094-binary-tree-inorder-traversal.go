/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {    
    stack := []*TreeNode{}
    curr := root
    res := []int{}
    
    for curr != nil || len(stack) > 0 {
        // reach the leftmost of the current node
        for curr != nil {
            stack = append(stack, curr)
            curr = curr.Left
        }
        
        // process the element on the top of the stack & remove it 
        curr = stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        
        res = append(res, curr.Val)
        
        curr = curr.Right
    }
    
    return res
}