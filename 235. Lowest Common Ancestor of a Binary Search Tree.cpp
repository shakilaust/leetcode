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

    TreeNode* lowestCommonAncestor(TreeNode* curNode, TreeNode* p, TreeNode* q) {
        if( curNode == NULL ) return NULL;
        if( curNode->val >= p->val && curNode->val <= q->val ) return curNode;
        if( curNode->val >= q->val && curNode->val <= p->val ) return curNode;
        if( curNode->val > p->val && curNode->val > q->val ) return lowestCommonAncestor( curNode->left, p, q );
        return lowestCommonAncestor( curNode->right , p , q );
    }
};
