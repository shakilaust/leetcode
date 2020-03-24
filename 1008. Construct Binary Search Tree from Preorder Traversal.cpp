/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* dfs(TreeNode* currentNode, int value) { 
    
    if(currentNode == NULL ) return new TreeNode(value);
    if( currentNode->val < value ) { 
        currentNode->right = dfs(currentNode->right, value);
    } else { 
        currentNode->left = dfs(currentNode->left, value);
    }
    
    return currentNode;

}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for( int i = 0 ; i < preorder.size() ; i++ ) { 
            root = dfs(root, preorder[i]);
        }
        
        return root;
    }
};
