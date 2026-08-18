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
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root ;
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->right);
        sum += node->val;
        node->val = sum;
        inorder(node->left);
    }
};