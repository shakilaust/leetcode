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
private:
    unordered_map< int, int > found;
public:
    void dfs(TreeNode* root, int level, vector < int > &ans) { 
        if( root == NULL ) return;
        if( !found[level] ) { 
            ans.push_back(root->val);
            found[level] = true;
        }
        
        dfs(root->right, level + 1 , ans );
        dfs( root->left, level + 1 , ans );
    }
    vector<int> rightSideView(TreeNode* root) {
        found.clear();
        vector < int > ans;
        dfs(root, 0, ans);
        return ans;
    }
};
