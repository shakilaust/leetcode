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
    vector<double> averageOfLevels(TreeNode* root) {
        vector < double > ans;
        list < TreeNode* > ls;
        ls.push_back(root);
        while( !ls.empty()) { 
            int sz = ls.size();
            double total = 0;
            for(TreeNode* cur: ls) { 
                total += cur->val;
            }
            
            ans.push_back( total / ( double ) sz );
            
            while( sz-- ) { 

                TreeNode* cur = ls.front();
                ls.pop_front();
                if( cur->left ) ls.push_back(cur->left);
                if( cur->right ) ls.push_back(cur->right);
            }

        }
        
        return ans;
    }
};
