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


int dfs(TreeNode* cur) { 
    if( cur == NULL ) return 0;
    int mx = dfs( cur->left ) + 1;
    mx = max( mx, dfs( cur->right) + 1);
    return mx;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if( root == NULL ) return true;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        return abs(lft - rgt) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
