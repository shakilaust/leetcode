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
    map < int, int > Idx;
    int idx = 0;
    vector < int > in, pre;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if( inorder.size() == 0 ) return NULL;
        in.clear();
        pre.clear();
        in.assign(inorder.begin(), inorder.end());
        pre.assign(preorder.begin(), preorder.end());
        Idx.clear();
        for(int i = 0; i < inorder.size(); i++ ) { 
            Idx[inorder[i]] = i;
        }
        idx = 0;
        return  generateTree(0 , inorder.size() - 1);
        
    }
    
    TreeNode* generateTree(int lft, int rgt) { 
        if(lft > rgt ) return NULL;
        int rootValue = pre[idx++];
        int rootIdx = Idx[rootValue];
        //printf("rootValue %d rootIdx: %d\n", rootValue, rootIdx);
        TreeNode* root = new TreeNode(rootValue);
        root->left = generateTree(lft, rootIdx - 1 );
        root->right = generateTree(rootIdx + 1 , rgt );
        return root;
    }
};
