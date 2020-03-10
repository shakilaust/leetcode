/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* node, vector< int> &ans) { 

    if( node == NULL ) return;
    dfs(node->left, ans);
    ans.push_back(node->val);
    dfs(node->right, ans);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector < int > ans;
        dfs(root, ans);
        return ans;
    }
};
