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
    
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if( root == NULL ){
            return {root, 0};
        }
        auto lft = dfs(root->left);
        auto rgt = dfs(root->right);
        
        if( lft.second < rgt.second ) {
            return {rgt.first, rgt.second + 1 };
        }
        if( lft.second > rgt.second ) {
            return {lft.first, lft.second + 1};
        }
        
        return {root, lft.second + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto ans = dfs( root );
        return ans.first;
    }
};
