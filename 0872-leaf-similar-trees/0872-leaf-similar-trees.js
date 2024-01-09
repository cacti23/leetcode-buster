/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
    const leaf1 = [];
    const leaf2 = [];
    
    dfs(root1, leaf1);
    dfs(root2, leaf2);
    
    // return leaf1.every((element, index) => element === leaf2[index]);
    return JSON.stringify(leaf1) === JSON.stringify(leaf2);
};

var dfs = function(root, leaf) {
    if(!root) return;
    
    if(!root.left && !root.right) {
        leaf.push(root.val);
    }
    
    dfs(root.left, leaf);
    dfs(root.right, leaf);
}


// tc -> O(n + m)
// sc -> O(n + m)