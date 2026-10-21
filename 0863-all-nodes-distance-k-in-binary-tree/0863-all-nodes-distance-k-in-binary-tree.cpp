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
    int cnt = 0;
    map<Node*, Node*> parent;
    set<Node*> st;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        parent[root] = nullptr;
        inorder(root);
        bfs(target, k, result);
        return result;
    }

    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            parent[root->left] = root;
        }

        if (root->right != nullptr) {
            parent[root->right] = root;
        }

        inorder(root->left);
        inorder(root->right);
    }

    void bfs(Node* target, int k, vector<int>& result) {
        queue<Node*> q;
        q.push(target);
        st.insert(target);
        int level = 0;

        while (!q.empty()) {

            if (level == k) {
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }

            int n = q.size();
            while (n--) {
                auto node = q.front();
                auto par = parent[node];
                q.pop();

                if (node->left != nullptr && !st.count(node->left)) {
                    st.insert(node->left);
                    q.push(node->left);
                }

                if (node->right != nullptr && !st.count(node->right)) {
                    st.insert(node->right);
                    q.push(node->right);
                }

                if (par != nullptr && !st.count(par)) {
                    st.insert(par);
                    q.push(par);
                }
            }

            level++;
        }
    }
};