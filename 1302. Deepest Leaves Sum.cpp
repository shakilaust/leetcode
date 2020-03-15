/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* node, int &mxDepth, int currentDepth, vector< int > &depth) {
    if( node == NULL ) return;
    mxDepth = max(mxDepth, currentDepth);
    if(depth.size() > 0 && depth.size() >= currentDepth ) {
        depth[currentDepth-1] += node->val;
    } else {
        depth.push_back(node->val);

   }
    dfs(node->left, mxDepth, currentDepth + 1, depth);
    dfs(node->right, mxDepth, currentDepth + 1 , depth);

}
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector< int > sum;
        int mx = 0;
        dfs(root, mx, 0, sum);
       
        return sum[mx-1];
        
    }
};
