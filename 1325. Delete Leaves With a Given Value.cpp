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
    
    bool dfs( TreeNode* curNode, int target) { 
        if( curNode == NULL ) return true;
        bool fromLeft = dfs( curNode->left, target );
        bool fromRight = dfs(curNode->right, target );
        
        if( fromLeft == true ) curNode->left = NULL;
        if( fromRight == true ) curNode->right = NULL;
        return fromLeft && fromRight && curNode->val == target;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool fromDfs = dfs( root, target );
        if( fromDfs ) return NULL;
        return root;
    }
};
