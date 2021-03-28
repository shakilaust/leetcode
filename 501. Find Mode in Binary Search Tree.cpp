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
    vector<int> findMode(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        unordered_map < int, int > freq;
        vector < int > ans;
        while( !q.empty() ){
            TreeNode* cur = q.front();
            q.pop();
            freq[cur->val]++;
            if( cur->left ) q.push( cur->left);
            if( cur->right ) q.push( cur->right);
        }
        int mx = -1;
        for( pair< int, int> cur: freq) {
            if( cur.second > mx ) {
                ans.clear();
                mx = cur.second;
                ans.push_back(cur.first);
            } else if( cur.second == mx ) {
                ans.push_back(cur.first);
            }
        }
        return ans;
    }
};
