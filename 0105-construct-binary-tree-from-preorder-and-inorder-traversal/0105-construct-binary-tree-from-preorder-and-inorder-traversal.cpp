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
using vi = vector<int>;
using vvi = vector<vector<int>>;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preo, vector<int>& ino) {
        int n = preo.size();
        int idx = 0;
        return solve(preo, ino, 0, n - 1, idx);
    }

    Node* solve(vi& preo, vi& ino, int st, int ed, int& idx) {
        if (st > ed) {
            return nullptr;
        }

        int i = st;
        int val = preo[idx];

        for (; i < ed; i++) {
            if (ino[i] == val) {
                break;
            }
        }

        Node* root = new Node(val);
        idx++;
        root->left = solve(preo, ino, st, i - 1, idx);
        root->right = solve(preo, ino, i + 1, ed, idx);

        return root;
    }
};