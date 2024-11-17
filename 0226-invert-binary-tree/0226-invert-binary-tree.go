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
    
    queue := []*TreeNode{root}
    
    for len(queue) > 0 {
        // get the first node
        node := queue[0]
        // remove the first node
        queue = queue[1:]
        
        // exchange the values
        node.Left, node.Right = node.Right, node.Left
        
        if node.Left != nil {
            queue = append(queue, node.Left)
        }
        
        if node.Right != nil {
            queue = append(queue, node.Right)
        }
    }
    
    return root
}

// tc -> O(n), number of nodes
// sc -> O(w), maximum width of tree, O(n) in the worst case