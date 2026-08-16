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
using Node = TreeNode;
class Solution {
public:
    int ops = 0;

    int distributeCoins(TreeNode* root) {
        int a = dfs(root);
        return ops;
    }

    int dfs(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        int extra = left + right + root->val - 1;
        ops += abs(extra);
        return extra;
    }
};