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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
    
private:
    // returns a pair: {max if we don't rob this node, max if we rob this node}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        // If we rob this node, cannot rob children
        int robNode = node->val + left.first + right.first;
        
        // If we don't rob this node, can choose to rob or not rob children
        int notRobNode = max(left.first, left.second) + max(right.first, right.second);
        
        return {notRobNode, robNode};
    }
};
