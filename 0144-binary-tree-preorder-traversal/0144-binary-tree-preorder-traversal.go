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
    
    *res = append(*res, root.Val)
    
    dfs(root.Left, res)
    dfs(root.Right, res)
}
func preorderTraversal(root *TreeNode) []int {
    res := []int{}
    dfs(root, &res) 
    
    return res
}