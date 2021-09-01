# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ans = None
        prv = None
        while l1 and l2:
            curNode = None
            if l1.val <= l2.val:
                curNode = ListNode(l1.val)
                l1 = l1.next
            else:
                curNode = ListNode(l2.val)
                l2 = l2.next
            
            if prv is None:
                ans = curNode
            else:
                prv.next = curNode
            
            prv = curNode
            
        while l1:
            curNode = ListNode(l1.val)
            l1 = l1.next
            if prv is None:
                ans = curNode
            else:
                prv.next = curNode
            prv = curNode
        
        while l2:
            curNode = ListNode(l2.val)
            l2 = l2.next
            if prv is None:
                ans = curNode
            else:
                prv.next = curNode
            prv = curNode
            
        return ans
                
                
        
