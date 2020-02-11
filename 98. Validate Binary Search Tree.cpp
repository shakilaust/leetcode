/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool dfs(TreeNode* root, TreeNode* low, TreeNode* high) { 
        
        if( root == NULL ) return true;
        if( low != NULL && root->val <= low->val ) return false;
        if( high != NULL && root->val >= high->val ) return false;
        return dfs(root->left , low , root ) && dfs(root->right, root, high);
        

    }
    bool isValidBST(TreeNode* root) {
       return dfs(root, NULL, NULL);
    }
};
