/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

map < int, int > cnt;
class Solution {
public:
    int treeTraversal(TreeNode *node) { 

       if(node == NULL ) return 0;
        int add = node->val;
        add += treeTraversal(node->left);
        add += treeTraversal(node->right);
        cnt[add]++;
        return add;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        cnt.clear();
        treeTraversal(root);
        int mx = 0;
        vector < int > ans;
        for(auto it: cnt) { 
            if(it.second > mx ) { 
                mx = it.second;
                ans.clear();
                ans.push_back(it.first);
            } else if( it.second == mx ) { 
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};
