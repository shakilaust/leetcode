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
public:
    /*
        One step right and then always left
    */
    int successor(TreeNode* curNode) {
        curNode = curNode->right;
        while( curNode->left != NULL ) curNode = curNode->left;
        return curNode->val;
    }
    /*
        One step left and then always right
    */
    int predecessor(TreeNode* curNode) {
        curNode = curNode->left;
        while( curNode->right != NULL ) curNode = curNode->right;
        return curNode->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root == NULL ) return NULL;
        if( key > root->val ) root->right = deleteNode(root->right, key );
        else if( key < root->val ) root->left = deleteNode( root->left, key );
        else {
            if( root->left == NULL && root->right == NULL ) root = NULL;
            else if( root->right != NULL ) {
                root->val = successor(root);
                root->right = deleteNode( root->right, root->val );
            } else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
            
           
        }
         return root;
    }
};
