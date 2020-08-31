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
    
    int dfs(TreeNode* curNode, int option, int &ans) { // option 0 for root, 1 for right, 2 for left
        if( curNode == NULL ) return 0;
        int fromLeft = dfs( curNode->left, 2 , ans );
        int fromRight = dfs( curNode->right, 1, ans );
        
        ans = max( ans, fromLeft );
        ans = max( ans, fromRight );
        
        if( option == 1 ) return fromLeft + 1;
        else if ( option == 2 ) return fromRight + 1;
        else return ans;

    }
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        return dfs( root, 0 , ans );
    }
};
