/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* dfs(TreeNode* currentNode, TreeNode* root, vector<TreeNode*> &ans, vector<int>& needToDeleted ) { 

    if(currentNode == NULL ) return currentNode;
    int value = currentNode->val;
    int low = lower_bound(needToDeleted.begin(), needToDeleted.end(), value) - needToDeleted.begin();
    int high = upper_bound(needToDeleted.begin(), needToDeleted.end(), value) - needToDeleted.begin();
   
    if( low == high) { 
        if( root == NULL ) {
        ans.push_back(currentNode);
        }
        currentNode->left = dfs(currentNode->left, currentNode, ans, needToDeleted);
        currentNode->right = dfs(currentNode->right, currentNode, ans, needToDeleted);
        return currentNode;
    }  else { 
        dfs(currentNode->left, NULL, ans, needToDeleted);
        dfs(currentNode->right, NULL, ans, needToDeleted);
        return NULL;
    }

}
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        sort(to_delete.begin(), to_delete.end());
        dfs(root, NULL, ans, to_delete);
        return ans;
    }
};
