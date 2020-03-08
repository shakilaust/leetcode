/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


map <  pair< TreeNode* , int >, int> dp;

int dfs(TreeNode* node, int taken) { 
    
    if( node == NULL ) return 0;
    if( dp.find(make_pair(node, taken)) != dp.end()) {
        return dp[make_pair(node, taken)];
    }
    int withOut = dfs(node->left, 0 ) + dfs(node->right, 0 );
    if( taken ) { 
        return dp[make_pair(node, taken)] = withOut;
    } else {
        
        int with = dfs(node->left, 1 ) + dfs(node->right, 1) + node->val;
        return dp[make_pair(node, taken)] = max(with, withOut);
        

    }

}
class Solution {
public:
    int rob(TreeNode* root) {
        dp.clear();
        return dfs(root, 0);
    }
};
