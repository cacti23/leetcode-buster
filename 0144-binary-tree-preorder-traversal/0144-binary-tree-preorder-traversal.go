/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    res := []int{}
    if root == nil {
        return res
    }
    
    stack := []*TreeNode{root}
    
    for len(stack) > 0 {
        node := stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        
        res = append(res, node.Val)
        
        if node.Right != nil {
            stack = append(stack, node.Right)
        }
        
        if node.Left != nil {
            stack = append(stack, node.Left)
        }
    }
    
    return res
}