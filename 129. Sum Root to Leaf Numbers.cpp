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
    int dfs( TreeNode* curNode, int val ) {
        if( curNode == NULL ) return val;
        int now = ( val * 10 ) + curNode->val;
        if( curNode->left == NULL && curNode->right == NULL ) return now;
        else if( curNode->left && curNode->right == NULL ) return dfs( curNode->left, now );
        else if( curNode->right && curNode->left == NULL ) return dfs( curNode->right, now );
        else return dfs(curNode->left, now ) + dfs( curNode->right , now );
    }
    int sumNumbers(TreeNode* root) {
        return dfs( root, 0 );
    }
};
