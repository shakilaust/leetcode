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
    int dfs(TreeNode* cur, int &ans) {
        if( cur == NULL ) {
            return 0;
        }
        
        int l = dfs( cur->left, ans );
        int r = dfs( cur->right, ans );
        
        ans += abs(l) + abs(r) ;
        return l + r + cur->val - 1;;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs( root, ans );
        return ans;
    }
};
