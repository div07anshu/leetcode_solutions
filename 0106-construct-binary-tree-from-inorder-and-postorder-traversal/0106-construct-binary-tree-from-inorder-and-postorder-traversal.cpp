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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n - 1;
        return solve(postorder, inorder, 0, n - 1, idx);
    }

    Node* solve(vi& postorder, vi& inorder, int st, int ed, int& idx) {
        if (st > ed) {
            return nullptr;
        }

        int rootVal = postorder[idx];
        idx--;
        int i = st;

        for (; i <= ed; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
        }

        Node* root = new Node(rootVal);
        root->right = solve(postorder, inorder, i + 1, ed, idx);
        root->left = solve(postorder, inorder, st, i - 1, idx);

        return root;
    }
};