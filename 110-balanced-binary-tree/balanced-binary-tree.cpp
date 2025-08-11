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
     
      int checkHeight(TreeNode* node){
        if(node == NULL)
        return 0;

        int LeftHeight = checkHeight(node->left);
        if(LeftHeight == -1)
        return -1;

        int rightHeight = checkHeight(node->right);
        if(rightHeight == -1)
        return -1;

        if(abs(LeftHeight - rightHeight) > 1)
        return -1;

        return max(LeftHeight, rightHeight)+1;
      }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};