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
    bool hasprev = false;
    int prev;
    int maxfreq = 0, currfreq = 0;

    vector<int> findMode(TreeNode* root) {
        vector<int> arr;
        dfs(root, arr);
        return arr;
    }

    void dfs(Node* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, arr);

        if (hasprev && prev == root->val) {
            currfreq++;
        } else {
            hasprev = true;
            prev = root->val;
            currfreq = 1;
        }

        if (currfreq > maxfreq) {
            maxfreq = currfreq;
            arr.clear();
            arr.push_back(root->val);
        } else if (currfreq == maxfreq) {
            arr.push_back(root->val);
        }

        dfs(root->right, arr);
    }
};