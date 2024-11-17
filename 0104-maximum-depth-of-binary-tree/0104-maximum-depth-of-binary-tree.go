/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    // bfs iterative
    if root == nil {
        return 0
    }
    
    queue := []*TreeNode{root}
    maxDepth := 0
    
    for len(queue) > 0 {
        size := len(queue)

        for i := 0; i < size; i++ {
            curr := queue[0]
            queue = queue[1:]
            
            if curr.Left != nil {
                queue = append(queue, curr.Left)
            }
            
            if curr.Right != nil {
                queue = append(queue, curr.Right)
            }
        }
        
        maxDepth++
    }
    
    return maxDepth
}

// tc -> O(n), n is number of total nodes
// sc -> O(h), h depth of tree