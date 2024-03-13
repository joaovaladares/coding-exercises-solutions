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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res = new TreeNode();

        if (root) {
            res->val = root->val;
            if (root->right != nullptr) res->left = invertTree(root->right);
            if (root->left != nullptr) res->right = invertTree(root->left);
        } else {
            return root;
        }
        
        return res;
    }
};