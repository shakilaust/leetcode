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
private:
    unordered_map< string, bool > present;
public:
    
    string traverse(TreeNode* cur, bool checked, bool right) { 
        if( cur == NULL) { 
            
            if( right ) { 
                return "r";
            }
            return "l";

        }
        string all = to_string(cur->val) +  traverse(cur->left, checked, false) + traverse(cur->right, checked, true);
        if( checked ) { 
            
             present[all] = true;
        }
        
        return all;
       
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        present.clear();
        traverse(s , true , false);
        string findOut = traverse(t, false, false);
        if( present[findOut] ) { 
            return true;
        }
        return false;
    }
};
