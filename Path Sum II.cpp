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

vector < vector < int > > ans;
vector< int> path;
void traverse(TreeNode *cur, int lft) {

    if(!cur->left && !cur->right ) // leaf node 
    {   
        if(lft == cur->val) {
            path.push_back(cur->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
    }
    if( cur->left  ) {
        path.push_back(cur->val);
        traverse(cur->left, lft - cur->val);
        path.pop_back();
    }
    if( cur->right ) {
        path.push_back(cur->val);
        traverse(cur->right, lft - cur->val);
        path.pop_back();
    }
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        path.clear();
        if(root) traverse(root, sum);
        return ans;
    }
};
