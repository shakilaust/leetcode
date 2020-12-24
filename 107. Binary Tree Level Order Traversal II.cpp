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


int dfs( TreeNode* now) {
    if( now == NULL ) return 0;
    int lft = dfs( now->left);
    int rgt = dfs( now->right );
    return max( lft, rgt ) + 1;
}
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue < TreeNode* > q;
        int totalLevels = dfs( root );
        vector < vector < int > > ans;
        if( totalLevels == 0 ) return ans;
       
        ans.resize(totalLevels);
        totalLevels--;
      //  cout << " ans Sz " << ans.size() << endl;
        q.push( root );
       

        while( !q.empty() ) {
            int sz = q.size();
         //   cout << " totalLevels " << totalLevels << " sz " << sz << endl;
            while( sz-- ) {
                TreeNode* now = q.front();
                ans[totalLevels].push_back( now->val);
                q.pop();
                if( now->left ) q.push(now->left);
                if( now->right ) q.push(now->right);
            }
            totalLevels--;
         
        }
         return ans;
    }
   
};
