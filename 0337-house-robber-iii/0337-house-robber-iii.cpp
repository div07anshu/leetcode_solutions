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


unordered_map<TreeNode*, int> dp[2];
using Node = TreeNode;

class Solution {
public:
    int rob(TreeNode* root) { return solve(root, 1); }

    int solve(Node* n, int cond) {
        if (n == nullptr) {
            return 0;
        }

        if (dp[cond].count(n)) {
            return dp[cond][n];
        }

        int take = INT_MIN;
        if (cond == 1) {
            take = n->val + solve(n->left, 0) + solve(n->right, 0);
        }

        int ntake = solve(n->left, 1) + solve(n->right, 1);

        return dp[cond][n] = max(take, ntake);
    }
};