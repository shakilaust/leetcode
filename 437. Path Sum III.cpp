/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs( TreeNode* root, int sum, int currentSum ) { 

    if( root == NULL ) return 0;
    currentSum = root->val + currentSum;
    
    return ( currentSum == sum ) + dfs( root->left, sum, currentSum ) + dfs( root->right , sum, currentSum );

}
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if( root == NULL ) return 0;
        return dfs( root, sum , 0 ) + pathSum( root->left, sum ) + pathSum( root->right, sum );
        
    }
};
