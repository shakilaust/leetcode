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
    vector<vector<int>> levelOrder(TreeNode* root) {
          vector< vector<int> > ans;
        if( root == NULL ) return ans;
        map < int, vector<int> > mp;
        queue < pair< TreeNode*, int > > q;
        q.push(make_pair(root, 0));
        while( !q.empty()) {
           TreeNode* node = q.front().first;
           int v = q.front().second;
           mp[q.front().second].push_back(node->val);
           q.pop();
            if( node->left ) { 
                q.push(make_pair(node->left, v + 1 ));
            }
            
            if( node-> right ) { 
                q.push(make_pair(node->right, v + 1 ) );
            }

        }

        for(auto it: mp) { 
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
