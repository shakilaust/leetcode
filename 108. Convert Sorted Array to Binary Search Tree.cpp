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


TreeNode* constructTree( int low, int high, vector< int >& nums) { 
    
    if( low > high ) return NULL;
    if( low == high ) return new TreeNode(nums[low]);
    
    int mid = ( low + high ) / 2ll;
    TreeNode* curNode = new TreeNode(nums[mid]);
    
    curNode->left = constructTree( low, mid - 1 , nums);
    curNode->right = constructTree(mid+1, high, nums );
    return curNode;

}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(0, nums.size() - 1 , nums );
    }
};
