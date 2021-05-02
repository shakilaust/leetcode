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
    void mxDepth( TreeNode* cur, int depth, int &mx) {
        if( cur ==  NULL ) return;
        mx =  max( mx, depth);
        mxDepth( cur->left, depth + 1, mx );
        mxDepth( cur->right, depth + 1, mx );
        
    }
    void dfs( TreeNode* cur, int mxDepth, int curDepth, int col, vector < vector <  string > > &ans) {
        if( cur == NULL ) return;
        ans[curDepth - 1][col] = to_string(cur->val);
        int p = ( mxDepth - curDepth - 1);
        int add =  p >= 0 ? ( 1 << p ) : 0 ;
        dfs( cur->left, mxDepth, curDepth + 1 , col - add , ans );
        dfs( cur->right, mxDepth, curDepth + 1, col + add , ans );
        
        
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int mx = 0;
        mxDepth( root, 1, mx );
        int cols = ( 1 << mx ) - 1;
        vector < vector < string > > ans;
        vector < string > add;
        for( int col = 0 ; col < cols ; col++ ) {
            add.push_back("");
        }
        for( int row = 0 ; row < mx ; row++ ) {
            ans.push_back( add );
        }
        int rootCol = ( 1 << ( mx - 1 ) ) - 1;
        dfs( root, mx, 1, rootCol, ans );
        return ans;
    }
    
};
