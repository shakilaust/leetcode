/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


const int noCamera = 0;
const int hasCamera = 1;
const int notNeeded = 2;

int ans;

int dfs(TreeNode* node) { 

        if(node == NULL ) return notNeeded;
        
        int lft = dfs(node->left);
        int rgt = dfs(node->right);
        
        if( lft == noCamera || rgt == noCamera ) { 
            ans++;
            return hasCamera;
        } else if ( lft == hasCamera || rgt == hasCamera ) { 
            return notNeeded;
        } else return noCamera;
    

}

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if( root == NULL ) return 0;
        ans = 0;
        if( dfs(root) == noCamera ) ans++;
        return ans;
    }
};
