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
    unordered_map<int, int> mp;
    int maxf = 0;
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);

        for (auto it : mp) {
            if (it.second == maxf) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }

    void dfs(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        mp[root->val]++;
        maxf = max(maxf, mp[root->val]);

        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};