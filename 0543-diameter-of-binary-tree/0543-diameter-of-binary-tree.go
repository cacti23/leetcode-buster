/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, count *int) int {
    // dfs recursive
    if root == nil {
        return 0
    }
    
    left := dfs(root.Left, count)
    right := dfs(root.Right, count)
    *count = max(*count, left + right)
    
    return 1 + max(left, right)
}

func diameterOfBinaryTree(root *TreeNode) int {
    res := 0
    dfs(root, &res)
    
    return res
}