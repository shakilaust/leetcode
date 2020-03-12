/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode* node, int oneDept, int twoDept) { 

    if( node == NULL ) { 
        return 0;
    }

    int value = twoDept ? node->val : 0;
    int evenValue = node->val % 2 == 0 ? 1 : 0;
    
    value += dfs(node->left , evenValue, oneDept );
    value += dfs(node->right, evenValue, oneDept );
    
    return value;
}
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, 0, 0);
    }
};
