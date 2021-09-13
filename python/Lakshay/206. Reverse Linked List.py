# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root = None
        prv = None
        while head:
            curNode = ListNode(head.val)
            root = curNode
            root.next = prv
            prv = curNode
            head = head.next
        
        return root
