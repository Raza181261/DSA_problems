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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root) return result;

        stack<TreeNode*> currLevel;
        stack<TreeNode*> nextLevel;

        vector<int> level;

        bool leftToRight = true;

        currLevel.push(root);

        while(!currLevel.empty()){
            TreeNode* temp = currLevel.top();
            currLevel.pop();

            if(temp){
                level.push_back(temp->val);

                if(leftToRight){
                    if(temp->left) nextLevel.push(temp->left);
                    if(temp->right) nextLevel.push(temp->right);
                }
                else{
                    if(temp->right) nextLevel.push(temp->right);
                    if(temp->left) nextLevel.push(temp->left);
                }
            }
            if(currLevel.empty()){
                result.push_back(level);
                level.clear();
                swap(currLevel,nextLevel);
                leftToRight = !leftToRight;
            }  
        }
        return result;
    }
};