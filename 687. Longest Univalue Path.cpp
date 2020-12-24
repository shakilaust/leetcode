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


int dfs(TreeNode* node, int &ans) {
    
    int fromLeft = 0;
    int fromRight = 0;
    if( node->left ) {
        fromLeft = dfs(node->left, ans) + 1;
    }
    if( node->right ) {
        fromRight = dfs(node->right, ans) + 1;
    }
    
    int mx = 0;
    
    if( fromLeft > 0 && node->val == node->left->val ) {
        ans = max( ans, fromLeft );
        mx = max( mx, fromLeft );
        
    }
    
    if( fromRight > 0 && node->val == node->right->val ) {
        ans = max( ans, fromRight );
        mx = max( mx,  fromRight );
    }
    
    if( fromRight > 0 & fromLeft > 0 ) {
        if( node->val == node->left->val && node->val == node->right->val ) { 
            ans = max( ans, fromLeft + fromRight );
        }
    }
    
    
    return mx;

}

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if( root == NULL ) return 0;
        int ans = 0;
        int rootMax = dfs( root, ans );
        return ans;
        
    }
};
