/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, res *bool) int {
    if root == nil {
        return 0
    }
    
    left := dfs(root.Left, res)
    right := dfs(root.Right, res)
    
    if left - right > 1 || right - left > 1 {
        *res = false
    }
    
    
    return 1 + max(left, right)
}

func isBalanced(root *TreeNode) bool {
    res := true
    dfs(root, &res)
    
    return res
}