/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* node, int cur, int &mx) { 
    
    if(node == NULL ) return;
    mx = max( mx, cur );
    dfs(node->left, cur + 1 , mx );
    dfs(node->right , cur + 1 , mx );

}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        dfs(root, 1, ans);
        return ans;
    }
};
