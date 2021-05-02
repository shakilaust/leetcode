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
    int maxLevelSum(TreeNode* root) {
       int mx = INT_MIN;
       int ans = -1;
       int currentLevel = 1;
       queue < TreeNode* > q;
        q.push( root );
        while( !q.empty()) {
            int sz = q.size();
            int sum = 0;
            while( sz-- ) {
                TreeNode* now = q.front();
                sum += now->val;
                q.pop();
                if( now->left ) {
                    q.push( now->left);
                }
                if( now->right) {
                    q.push(now->right);
                }
            }
            if( sum > mx ) {
                mx = sum;
                ans = currentLevel;
            }
            currentLevel++;
        }
        return ans;
    }
};
