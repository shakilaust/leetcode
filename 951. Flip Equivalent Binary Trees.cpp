/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void dfs(TreeNode* node, vector < vector < int > > &graph) { 
    
    if( node == NULL ) return;
    graph[node->val].push_back(0);
    if(node->left) {
        graph[node->val].push_back(node->left->val);
        dfs(node->left, graph);
    }
    if( node->right ) { 

        graph[node->val].push_back(node->right->val);
        dfs(node->right, graph);
    }
    
}
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector < vector < int > > a( 105 );
        vector < vector < int > > b(105 );
        dfs(root1, a);
        dfs(root2, b);
        for( int i = 0 ; i < 100 ; i++ ) { 
            
            if(a[i].size() != b[i].size()) return false;
            sort(a[i].begin(), a[i].end());
            sort(b[i].begin(), b[i].end());
            for( int j = 0 ; j < a[i].size() ; j++ ) { 
                if(a[i][j] != b[i][j] ) return false;
            }

        }
        
        
        return true;
    }
};
