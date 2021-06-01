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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue < TreeNode *> o,c;
        o.push(original);
        c.push(cloned);
        while( !o.empty() ) {
            TreeNode* now = o.front();
            if( now == target ) {
                return c.front();
            }
            TreeNode* fromC = c.front();
            c.pop();
            o.pop();
            if( now->left ) {
                c.push(fromC->left);
                o.push(now->left);
            }
            if( now->right ) {
                c.push(fromC->right);
                o.push(now->right);
            }
        }
        
        return NULL;
    }
};
