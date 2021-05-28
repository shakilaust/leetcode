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
    unordered_map < int , int > pos;
    vector < int > pstOrd;
    int idx;
    TreeNode* dfs(int low, int high) {
        if( low > high ) return NULL;
        int val = pstOrd[idx--];
        TreeNode* root = new TreeNode(val);
        int p = pos[val];
       
        root->right = dfs( p + 1, high);
         root->left = dfs(low, p - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pstOrd = postorder;
        idx = pstOrd.size() - 1;
        for( int i = 0 ; i < inorder.size() ; i++ ) {
            pos[inorder[i]] = i;
        }
        return dfs( 0 , idx );
        
    }
};
