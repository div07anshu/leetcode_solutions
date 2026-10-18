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
    vector<int> arr;
    TreeNode* balanceBST(TreeNode* root) {
        trav(root);
        return build(0, arr.size() - 1);
    }

    void trav(Node* node) {
        if (node == nullptr) {
            return;
        }

        trav(node->left);
        arr.push_back(node->val);
        trav(node->right);
    }

    Node* build(int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int mid = l + (r - l) / 2;
        Node* root = new Node(arr[mid]);
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);

        return root;
    }
};