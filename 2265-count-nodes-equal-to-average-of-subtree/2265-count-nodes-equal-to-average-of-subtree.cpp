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
    int count = 0;
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }

    pair<int, int> dfs(Node* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        auto lh = dfs(node->left);
        auto rh = dfs(node->right);
        int sum = node->val + lh.first + rh.first;
        int cnt = 1 + lh.second + rh.second;

        if (node->val == sum / cnt) {
            count++;
        }

        return {sum, cnt};
    }
};