/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using Node = TreeNode;
class Solution {
public:
    Node* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool cond = dfs(root, p, q);
        return ans;
    }

    bool dfs(Node* node, Node* p, Node* q) {
        if (node == nullptr) {
            return false;
        }

        bool self = (node->val == p->val) || (node->val == q->val);

        bool left = dfs(node->left, p, q);
        bool right = dfs(node->right, p, q);

        if ((self && left) || (self && right) || (left && right)) {
            ans = node;
        }

        return self || left || right;
    }
};