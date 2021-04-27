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
    int minDepth(TreeNode* root) {
        int ans = 0;
        if( root == NULL ) return ans;
        queue < int > depth;
        depth.push( 1 );
        queue < TreeNode* > q;
    
        q.push( root );
        while( !q.empty() ) {
            TreeNode* curNode = q.front();
            q.pop();
            int d = depth.front();
            depth.pop();
            if( curNode->left == NULL && curNode->right == NULL ) {
                return d;
            }
            if( curNode->left ) {
                depth.push( d + 1 );
                q.push(curNode->left);
            }
            if( curNode->right ) {
                depth.push( d + 1 );
                q.push( curNode->right);
            }
        }
        
        
        return 0;
    }
};
