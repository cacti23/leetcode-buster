/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, res *[]int) {
    if root == nil {
        return
    }
    
    dfs(root.Left, res)
    *res = append(*res, root.Val)
    dfs(root.Right, res)
}

func inorderTraversal(root *TreeNode) []int {
    res := []int{}
    dfs(root, &res)
    
    return res
}