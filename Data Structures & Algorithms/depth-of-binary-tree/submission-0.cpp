/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        stack<pair<TreeNode*, int>> st;
        int depth = 0, i = 1;
        st.push({root, i});

        while (!st.empty()) {
            auto [node, pos] = st.top();
            st.pop();
            i = pos + 1;;
            if (node->right) {
                st.push({node->right, i});
            }
            if (node->left) {
                st.push({node->left, i});
            }
            depth = max(depth, pos);
        }
        return depth;
    }
};
