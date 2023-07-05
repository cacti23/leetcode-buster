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
    int solve(TreeNode* node, int& dia) {
        // base case
        if(node == NULL) return 0;
        
        int leftHeight = solve(node -> left, dia);
        int rightHeight = solve(node -> right, dia);
        
        dia = max(dia, leftHeight + rightHeight);
        
        return (1 + max(leftHeight, rightHeight));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        int ans = INT_MIN;
        
        solve(root, ans);
        
        return ans;
    }
};