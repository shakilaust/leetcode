/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* dfs(TreeNode* t1, TreeNode* t2) { 
    
    if( t1 == NULL && t2 == NULL ) return NULL;
    int a = t1 ? t1->val : 0;
    int b = t2 ? t2->val : 0;
    TreeNode* current = new TreeNode(a + b);
    current->left = dfs( t1 ? t1->left : NULL, t2 ? t2->left : NULL );
    current->right = dfs(t1 ? t1->right : NULL, t2 ? t2->right : NULL );
    return current;


}
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }
};
