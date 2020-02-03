/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    
public:
   
     stack < int > st;
    void generateStack(TreeNode* node) { 
        if( node == NULL ) return;
        generateStack(node->right);
        st.push(node->val);
        generateStack(node->left);

    }
    BSTIterator(TreeNode* root) {
        generateStack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int nxt = st.top();
        st.pop();
        return nxt;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
