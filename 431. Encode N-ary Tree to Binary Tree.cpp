/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        
        if( root == NULL ) return NULL;
        TreeNode* newRoot = new TreeNode(root->val);
        
        if(root->children.size() > 0 ) { 
            newRoot->left = encode(root->children[0]);
        }
        
        TreeNode* shiblings = newRoot->left;
        for( int i = 1 ; i < root->children.size() ; i++ ) { 
            shiblings->right = encode(root->children[i]);
            shiblings = shiblings->right;
        }
        
        return newRoot;
        
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(root == NULL ) return NULL;
        vector <Node*> children;
        Node* newRoot = new Node(root->val, children );
        TreeNode* child = root->left;
        while(child != NULL ) { 
            
            newRoot->children.push_back(decode(child));
            child = child->right;
        }
        return newRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
