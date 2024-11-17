/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    // using recursive dfs
    if root == nil {
        return 0
    }
    
    return 1 + max(maxDepth(root.Left), maxDepth(root.Right))
}

// tc -> O(n), n is the number of nodes present
// sc -> O(h), maximum height of tree