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
public:
    vector < int > ans;
    
    void inOrderTraversal(TreeNode *root) { 
        if( root == NULL ) return;
        inOrderTraversal(root->left);
        ans.push_back(root->val);
        inOrderTraversal(root->right);

    }
    int kthSmallest(TreeNode* root, int k) {
        ans.clear();
        inOrderTraversal(root);
        return ans[k-1];
    }
};
