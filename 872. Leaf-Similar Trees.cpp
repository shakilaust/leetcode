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
    void dfs(TreeNode* now, vector< int > &store) {
        if( now == NULL ) return;
        if( now->left == NULL && now->right == NULL ) {
            store.push_back(now->val);
            return;
        }
        dfs( now->left, store );
        dfs( now->right, store );
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector < int > one, two;
        dfs( root1, one );
        dfs( root2, two );
        int sz1 = one.size();
        int sz2 = two.size();
        if( sz1 != sz2 ) return false;
        for( int i = 0 ; i < sz1 ; i++ ) {
            if( one[i] != two[i])  { 
                return false;
            }
        }
        return true;
    }
};
