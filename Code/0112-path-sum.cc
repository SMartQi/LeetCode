/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        return helper(root, sum);
    }
    
    bool helper(TreeNode* root, int sum) {
        if (root->left && root->right) {
            return helper(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        }
        if (root->left) {
            return helper(root->left, sum - root->val);
        }
        if (root->right) {
            return helper(root->right, sum - root->val);
        }
        return (sum == root->val);
    }
};