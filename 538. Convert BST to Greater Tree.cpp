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

    TreeNode* convertBST(TreeNode* root) {
        int add = 0;
        stack < TreeNode* > st;
        TreeNode* currentNode = root;
        
        while( !st.empty() || currentNode != NULL ) {
            while( currentNode != NULL ) {
                st.push( currentNode );
                currentNode = currentNode->right;
            }
            currentNode = st.top();
            st.pop();
            currentNode->val += add;
            add = currentNode->val;
            currentNode = currentNode->left;
        }
        return root;
    }
};
