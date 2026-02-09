/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValide(TreeNode* Node, long minVal, long maxVal) {
        if (Node == NULL)
            return true;
        if (Node->val <= minVal || Node->val >= maxVal)
            return false;
        return isValide(Node->left, minVal, Node->val) &&
               isValide(Node->right, Node->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return isValide(root, LONG_MIN, LONG_MAX);
    }
};