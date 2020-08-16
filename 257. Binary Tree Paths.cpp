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
    
    void dfs(TreeNode* node, string sofar, vector < string > &ans ) { 
        
        if( node == NULL ) return;
        if( node && node->left == NULL && node->right == NULL ) { 
            ans.push_back(  sofar.size() > 0 ? sofar + "->" + to_string(node->val) : to_string(node->val) );
            return;
        }
        if( node->left) {
            dfs( node->left, sofar.size() > 0 ? sofar + "->" + to_string(node->val) : to_string(node->val) , ans );
        }
        
        if( node->right ) {
             dfs( node->right, sofar.size() > 0 ? sofar + "->" + to_string(node->val) : to_string(node->val) , ans );
        }
       
        

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector < string > ans;
        dfs( root, "", ans );
        return ans;
    }
};
