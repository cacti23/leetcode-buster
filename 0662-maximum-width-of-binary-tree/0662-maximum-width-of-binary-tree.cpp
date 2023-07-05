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
    int widthOfBinaryTree(TreeNode* root) {
        // node and index
        queue<pair<TreeNode*, int>> q;
        
        // insert the root node
        q.push({root, 0});
        
        int ans = 0;
        
        while(!q.empty()) {
            // first element will represent the current minimum index of the level
            int currMin = q.front().second;
            int size = q.size();
            long long leftMost, rightMost;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                // subtract to prevent integer overflow to next level
                long long currId = q.front().second - currMin;
                q.pop();
                
                if(i == 0) leftMost = currId;
                
                if(i == size - 1) rightMost = currId;
                
                if(node -> left) q.push({node -> left, currId * 2 + 1});
                
                if(node -> right) q.push({node -> right, currId * 2 + 2});
                
            }
            // level wise check the width
            ans = max(ans, static_cast<int>(rightMost - leftMost + 1));
        }
        
        return ans;
    }
};