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
    void dfs(TreeNode* cur, bool isLeft, int &ans ) {
        if( cur == NULL ) return;
        if( isLeft && cur->left == NULL && cur->right == NULL ) {
            ans += cur->val;
        }
        dfs( cur->left, true, ans );
        dfs( cur->right, false, ans );
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs( root, false, ans );
        return ans;
    }
};
