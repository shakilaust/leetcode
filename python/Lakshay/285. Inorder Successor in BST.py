# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        
        def bst_taversal(root: 'TreeNode', parent: 'TreeNode'):
            if root is None:
                return
            root.parent = parent
            bst_taversal( root.left, root )
            bst_taversal( root.right, root )
        
        bst_taversal(root, None)
        
        def right_child_present(node: 'TreeNode'):
            node = node.right
            while node.left:
                node = node.left
            return node
        
        def right_child_is_not_present(node: 'TreeNode', child: 'TreeNode'):
            if node is None:
                return None
            if node.left == child:
                return node
            return right_child_is_not_present( node.parent, node)
        
        while root and root!= p:
            if root.val > p.val:
                root = root.left
            else:
                root = root.right
        
        if root is None:
            return None
        
        if root.right:
            return right_child_present(root)
        else:
            return right_child_is_not_present(root.parent, root)
                
