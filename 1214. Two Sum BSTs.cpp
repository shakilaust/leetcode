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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_map < int, bool > required;
        queue <TreeNode* > q;
        q.push(root1);
        while(!q.empty()) { 
            TreeNode* currentNode = q.front();
            required[target - currentNode->val] = true;
            q.pop();
            if(currentNode->left) { 
                q.push(currentNode->left);
            }
            if(currentNode->right) { 
                q.push(currentNode->right);
            }

        }
        q.push(root2);
         while(!q.empty()) { 
            TreeNode* currentNode = q.front();
            if(required[currentNode->val] == true ) return true;
            q.pop();
            if(currentNode->left) { 
                q.push(currentNode->left);
            }
            if(currentNode->right) { 
                q.push(currentNode->right);
            }

        }
        return false;
        
    }
};
