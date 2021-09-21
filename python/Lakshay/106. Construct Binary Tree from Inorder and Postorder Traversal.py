# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        idx = len(postorder) - 1
        inordered_pos = {}
        for index, value in enumerate(inorder):
            inordered_pos[value] = index

        def dfs(low, high):
            nonlocal idx
            if low > high:
                return None
            root_val = postorder[idx]
            idx -= 1
            root = TreeNode(root_val)

            mid = inordered_pos[root_val]
            root.right = dfs( mid + 1, high )
            root.left = dfs( low, mid - 1)
           
            return root
        return dfs( 0 , len(postorder) - 1 )  
