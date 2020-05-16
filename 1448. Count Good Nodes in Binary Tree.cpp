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


int dfs(TreeNode* root, int mx) {

    if( root == NULL ) return 0;
    int add = 0;
    int curMax = mx;
    if( root->val >= mx ) {
        add = 1;
        curMax = root->val;
    }
    return dfs(root->left, curMax) + dfs(root->right, curMax) + add;
}
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, -INT_MAX);
    }
};
