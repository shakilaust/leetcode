/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* dfs(int lft, int rgt, vector< int >&nums) { 

    if( lft > rgt ) return NULL;
    int mxIdx = lft;
    
    for( int i = lft + 1 ; i <= rgt ; i++ ) { 
        if( nums[mxIdx] < nums[i] ) { 
            mxIdx = i;
        }
    }
    
    TreeNode* node = new TreeNode(nums[mxIdx]);
    node->left = dfs(lft , mxIdx - 1 , nums );
    node->right = dfs(mxIdx + 1 , rgt , nums );
    return node;

}

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};
