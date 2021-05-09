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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map < int, map < int, vector < int > > > nodes;
        queue < TreeNode* > q;
        q.push(root);
        queue < pair < int, int > > order;
        order.push({0,0});
        while( !q.empty() ) {
            TreeNode* now = q.front();
            q.pop();
            pair < int, int > o = order.front();
            order.pop();
            nodes[o.second][o.first].push_back(now->val);
            if( now->left ) {
                q.push( now->left );
                order.push( {o.first + 1, o.second - 1 });
            }
            if( now->right ) {
                q.push( now->right );
                order.push( {o.first + 1, o.second + 1} );
            }
        }
        vector < vector < int > > ans;
        for( auto values: nodes ) {
            vector < int > tmp;
            for( auto now: values.second ) {
                sort( now.second.begin(), now.second.end() );
                for( auto add: now.second ) {
                    tmp.push_back(add);
                }
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
