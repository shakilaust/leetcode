/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


int dfs( TreeNode* node, int &ans) { 
    if( node == NULL ) return 0;
    int left = 0, rgt = 0;
    
    if(node->left) { 
        left = dfs(node->left, ans) + 1;
    }
    
    if( node->right ) { 
        rgt = dfs( node->right, ans) + 1;
    }

   ans = max( ans, left + rgt );
    cout << " cur " << node->val << " lft " << left << " rgt " << rgt << " ans " << ans << endl;
    
    
    return max( left , rgt );


}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs( root, ans );
        return ans;
    }
};
