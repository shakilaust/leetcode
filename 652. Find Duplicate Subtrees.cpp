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
    
    unordered_map< string, int > cnt;
    vector <TreeNode* > ans;
    
    string dfs(TreeNode* node) { 
            
        if(node == NULL ) return "#";
        string lft = dfs(node->left);
        string rgt = dfs(node->right);
        string subtree = to_string(node->val) + lft + rgt;
        cnt[subtree]++;
        if(cnt[subtree] == 2 ) { 
            ans.push_back(node);
        }
        
        return subtree;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        cnt.clear();
        ans.clear();
        dfs(root);
        return ans;
    }
};
