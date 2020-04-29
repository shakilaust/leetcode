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

int dfs(TreeNode* &node, int sum) { 
    if( node == NULL ) return sum;
    int add = dfs( node->right, sum );
    add += node->val;
    node->val = add;
    return dfs( node->left, add );
   
}
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs( root, 0 );
        return root;
    }
};
