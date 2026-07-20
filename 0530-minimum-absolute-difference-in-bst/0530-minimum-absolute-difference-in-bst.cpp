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
    priority_queue<int> pq;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int mind = INT_MAX;
        int top = pq.top();
        pq.pop();

        while (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            mind = min(mind, top - num);
            top = num;
        }

        return mind;
    }

    void dfs(Node* root) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left);
        dfs(root->right);
        pq.push(root->val);
    }
};