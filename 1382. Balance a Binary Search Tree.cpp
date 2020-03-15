/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void storeBSTNodes(TreeNode* root, vector<TreeNode*> &nodes) 
{ 
    // Base case 
    if (root==NULL) 
        return; 
  
    // Store nodes in Inorder (which is sorted 
    // order for BST) 
    storeBSTNodes(root->left, nodes); 
    nodes.push_back(root); 
    storeBSTNodes(root->right, nodes); 
} 
  
/* Recursive function to construct binary tree */
TreeNode* buildTreeUtil(vector<TreeNode*> &nodes, int start, 
                   int end) 
{ 
    // base case 
    if (start > end) 
        return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    TreeNode *root = nodes[mid]; 
  
    /* Using index in Inorder traversal, construct 
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1); 
    root->right = buildTreeUtil(nodes, mid+1, end); 
  
    return root; 
} 
  

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
         vector<TreeNode *> nodes; 
    storeBSTNodes(root, nodes); 
  
    // Constucts BST from nodes[] 
    int n = nodes.size(); 
    return buildTreeUtil(nodes, 0, n-1); 
    }
};
