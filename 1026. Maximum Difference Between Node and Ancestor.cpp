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
    pair< pair<int,int>, int > dfs(TreeNode* curNode) {
        if( curNode == NULL ) {
            return make_pair(make_pair(INT_MIN, INT_MAX),0);
        }
        pair< pair<int,int>, int > lft = dfs( curNode->left );
         pair< pair<int,int>, int > rgt = dfs( curNode->right );
        
        int mx = max( lft.first.first, rgt.first.first );
        int mn = min( lft.first.second, rgt.first.second );
        int mxAns = max( lft.second, rgt.second );
        mx = max( mx, curNode->val);
        mn = min( mn, curNode->val);
       // cout << " mx " << mx << " mn " << mn;
        int ans = max( abs( curNode->val - mx ), abs( curNode->val - mn ) );
   //     cout << " curNode->val " << curNode->val << endl;
    
        return make_pair( make_pair( mx, mn), max( ans, mxAns));
    }
    int maxAncestorDiff(TreeNode* root) {
        pair< pair<int,int>, int > getValue = dfs(root);
        return getValue.second;
    }
};
