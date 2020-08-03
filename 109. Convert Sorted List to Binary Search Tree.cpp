/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

vector < int > sortedValues;
    
public:
    TreeNode* dfs( int low, int high) { 
        if( low > high ) return NULL;
        int mid = ( low + high ) / 2;
        TreeNode* root = new TreeNode(sortedValues[mid]);
        root->left = dfs(low, mid - 1 );
        root->right = dfs(mid + 1 , high );
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        sortedValues.clear();
        while(head) { 
            sortedValues.push_back(head->val);
            head = head->next;
        }
        return dfs(0 , sortedValues.size() - 1 );
    }
};
