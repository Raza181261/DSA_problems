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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int maxVal){
        if(!node)
        return 0;

        int good = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal,node->val);

        good += dfs(node->left,maxVal);
        good += dfs(node->right,maxVal);

        return good;
    }
};