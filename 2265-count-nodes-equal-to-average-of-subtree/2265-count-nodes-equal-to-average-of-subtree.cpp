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

    void dfs(Node* node) {
        if (node == nullptr) {
            return;
        }

        int sum = 0, cnt = 0;
        solve(node, sum, cnt);
        int avg = sum / cnt;

        if (node->val == avg) {
            count++;
        }

        dfs(node->left);
        dfs(node->right);
    }

    void solve(Node* node, int& sum, int& cnt) {
        if (node == nullptr) {
            return;
        }

        sum += node->val;
        cnt++;
        solve(node->left, sum, cnt);
        solve(node->right, sum, cnt);
    }
};