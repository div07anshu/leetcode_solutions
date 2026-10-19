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
    vector<TreeNode*> generateTrees(int n) { return solve(1, n); }

    vector<Node*> solve(int l, int r) {
        if (l > r) {
            return {nullptr};
        } else if (l == r) {
            Node* node = new Node(l);
            return {node};
        }

        vector<Node*> result;
        for (int i = l; i <= r; i++) {
            vector<Node*> left_bst = solve(l, i - 1);
            vector<Node*> right_bst = solve(i + 1, r);

            for (auto left_root : left_bst) {
                for (auto right_root : right_bst) {
                    Node* root = new Node(i);
                    root->left = left_root;
                    root->right = right_root;

                    result.push_back(root);
                }
            }
        }

        return result;
    }
};