/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        vector<TreeNode*> q = {root}, next;
        
        while (!q.empty()) {
            ans.push_back({});
            for (TreeNode *node : q) {
                ans.back().push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            q.swap(next);
            next.clear();
        }
        return ans;
    }
};
