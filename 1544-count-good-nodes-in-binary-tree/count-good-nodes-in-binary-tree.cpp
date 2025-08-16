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
    void Countgoodnodes(TreeNode* root, int& count, int max){
        if(!root) return;
        if(root->val >= max){
            count++;
            max = root->val;
        }
        Countgoodnodes(root->left,count,max);
        Countgoodnodes(root->right,count,max);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        if(!root) return count;
        Countgoodnodes(root,count,root->val);

        return count;
    }
};