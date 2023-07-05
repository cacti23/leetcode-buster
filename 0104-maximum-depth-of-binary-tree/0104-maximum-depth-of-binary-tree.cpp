/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* node) {
        // base case
        if(node == NULL) return 0;
        
        int leftHeight = solve(node -> left);
        int rightHeight = solve(node -> right);
        
        return (1 + max(leftHeight, rightHeight));
    }
    int maxDepth(TreeNode* root) {
        
        
        return solve(root);
    }
};