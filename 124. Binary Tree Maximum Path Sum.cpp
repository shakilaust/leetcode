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
const int INF = 1e8;
int dfs(TreeNode* node, int &ans) { 
    if( node == NULL ) return -INF;
    int cur = node->val;
    int lft = dfs( node->left , ans);
    int rgt = dfs( node->right, ans );
    int subtreeMax = cur;
    subtreeMax = max( subtreeMax, cur + lft );
    subtreeMax = max( subtreeMax, cur + rgt );
    ans = max( ans , cur + lft + rgt );
    ans = max( ans , subtreeMax );
    return subtreeMax;

}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = -INF;
        dfs(root, ans );
        return ans;
    }
};
