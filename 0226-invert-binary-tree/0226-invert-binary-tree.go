/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    
    // swap left and right chilren
    root.Left, root.Right = root.Right, root.Left
    
    invertTree(root.Left)
    invertTree(root.Right)
    
    return root
}

// tc -> O(n), n is the number of nodes in the tree
// sc -> O(h), h is the height of the tree