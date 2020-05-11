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
private:
 
TreeNode* dfs(TreeNode* root) { 
      if(root->left == NULL && root->right == NULL ) return root;
        TreeNode* lastNode;
        if(root->left == NULL ) {
            lastNode = dfs(root->right);
        } else { 

            lastNode = dfs(root->left);
            if( root->right == NULL ) {
                root->right = root->left;
            } else {
                TreeNode* rightChild = root->right;
                root->right = root->left;
                lastNode->right = rightChild;
                lastNode = dfs(rightChild);
            }
            
            root->left = NULL;
        }
        
        return lastNode;
}
public:
    void flatten(TreeNode* root) {
        if(root) dfs(root);
        
    }
};
