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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
        return {};

        vector<int> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
             TreeNode* rightmostNode = nullptr;

             for(int i = 0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                // Add children to the queue
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            rightmostNode = node;
             }
             result.push_back(rightmostNode->val);
        }
        return result;
    }
};