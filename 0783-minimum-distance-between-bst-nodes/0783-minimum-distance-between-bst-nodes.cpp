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
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        diff(root, arr);
        int mind = INT_MAX;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            mind = min(mind, arr[i] - arr[i - 1]);
        }

        return mind;
    }

    void diff(Node* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }

        diff(root->left, arr);
        arr.push_back(root->val);
        diff(root->right, arr);
    }
};