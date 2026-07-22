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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return build(0, n - 1, nums);
    }

    TreeNode* build(int left, int right, vector<int>& nums) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        Node* a = new Node(nums[mid]);
        a->left = build(left, mid - 1, nums);
        a->right = build(mid + 1, right, nums);

        return a;
    }
};