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
    map<TreeNode*, TreeNode*> parent;
    set<TreeNode*> visit;
    vector< int > ans;
    void traverse(TreeNode* node) { 
        if(node->left) { 
            parent[node->left] = node;
            traverse(node->left);
        }
        if(node->right) { 
            parent[node->right] = node;
            traverse(node->right);
        }
    }

    void dfs(TreeNode* node, int k ) { 

        if(visit.find(node) != visit.end()) return;
        visit.insert(node);
        if( k == 0 ) { 
            ans.push_back(node->val);
            return;

         }

        if( node->left ) dfs( node->left , k - 1 );
        if( node->right ) dfs( node->right, k - 1 );
        if(parent[node] ) dfs(parent[node], k - 1 );

    }

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverse(root);
        dfs(target, k);
        return ans;
    }
};
