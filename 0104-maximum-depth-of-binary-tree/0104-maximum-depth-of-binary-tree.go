/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    // dfs recursive
    if root == nil {
        return 0
    }
    
    left := maxDepth(root.Left)
    right := maxDepth(root.Right)
    
    return 1 + max(left, right)
}

// tc -> O(n), n is number of total nodes
// sc -> O(h), h depth of tree