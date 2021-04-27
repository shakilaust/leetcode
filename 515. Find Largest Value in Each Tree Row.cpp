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
    vector<int> largestValues(TreeNode* root) {
        vector < int > ans;
        queue < TreeNode* > q;
        if( root == NULL ) return ans;
        q.push( root );
        while( !q.empty() ) {
            int sz = q.size();
            bool f = true;
            int mx;
            while( sz-- ) {
                TreeNode* now = q.front();
                q.pop();
                if( f || now->val > mx ) {
                    mx = now->val;
                    f = false;
                }
                if( now->left ) {
                    q.push(now->left);
                }
                if( now->right) {
                    q.push(now->right);
                }
            
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
