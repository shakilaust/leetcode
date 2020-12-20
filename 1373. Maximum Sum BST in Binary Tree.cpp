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

const int NX = 40000 + 5;
class Solution {

  int sum[ NX ], lft[ NX ], rgt[ NX ], node, isBst[ NX ], ans;
  int mx[ NX], mn[ NX ];
    
  int dfs( TreeNode* curNode) {
      if( curNode == NULL ) return 0;
      int curIdx = ++node;
      lft[curIdx] = dfs(curNode->left);
      rgt[curIdx] = dfs(curNode->right);
      mx[ curIdx ] = max( curNode->val, max( mx[lft[curIdx]], mx[ rgt[curIdx]] ));
      mn[ curIdx ] = min( curNode->val, min( mn[lft[curIdx]], mn[ rgt[curIdx]] ));
      sum[ curIdx ] = curNode->val + sum[lft[curIdx]] + sum[rgt[curIdx]];
      isBst[curIdx] = isBst[lft[curIdx]] && isBst[rgt[curIdx]] && mx[lft[curIdx]] < curNode->val && curNode->val < mn[rgt[curIdx]];
      if( isBst[curIdx] ) {
          ans = max( ans, sum[curIdx] );
      }
      return curIdx;
      
  }
public:
    int maxSumBST(TreeNode* root) {
        sum[0] = 0;
        ans = 0;
        node = 0;
        isBst[0] = 1;
        mx[0] = -NX;
        mn[0] = NX;
        dfs(root);
        return ans;
    }
};
