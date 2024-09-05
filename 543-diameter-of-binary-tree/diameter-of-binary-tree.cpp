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
       int maxD = 0;
       int height(TreeNode* node){
        if(node == nullptr)
        return 0;

        int leftHight = height(node -> left);
        int rightHight = height(node -> right);

        maxD = max(maxD, leftHight + rightHight);

        return max(leftHight, rightHight)+1;

        


       }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxD;

        
    }
};