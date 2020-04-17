/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

unordered_map<TreeNode*, TreeNode*> parent;

void dfs(TreeNode* curNode, TreeNode* root) { 

    if( curNode == NULL ) return;
    parent[curNode] = root;
    dfs(curNode->left, curNode);
    dfs(curNode->right, curNode);
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, NULL);
        unordered_map< TreeNode*, bool > isPresent;
        TreeNode* curNode = p;
        while( curNode ) { 
            isPresent[curNode] = true;
            curNode = parent[curNode];
        }
        
        TreeNode* ans = NULL;
        curNode = q;
        while(curNode) { 
            if(isPresent[curNode] ) { 
                ans = curNode;
                break;
            }
            curNode = parent[curNode];
        }
        return ans;
    }
};
