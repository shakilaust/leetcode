/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void pushInVector(TreeNode *root, vector < int > &ans) { 
        queue <TreeNode* > q;
        q.push(root);
        while(!q.empty()) { 
            TreeNode *now = q.front();
            q.pop();
            if( now == NULL ) continue;
            ans.push_back(now->val);
            q.push(now->left);
            q.push(now->right);
        }

}
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector < int > ans;
        pushInVector(root1, ans);
        pushInVector(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
       
    }
};
