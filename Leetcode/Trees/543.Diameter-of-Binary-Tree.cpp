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
    vector<int> ans = {0};

    int dfs(TreeNode* root) {
        if (root == nullptr) return -1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans[0] = max(ans[0], 2 + left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans[0];
    }
};