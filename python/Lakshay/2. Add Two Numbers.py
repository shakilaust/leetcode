# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        
        root = None
        prv = None 
        carry = 0
        
        while l1 and l2:
            digit_sum = l1.val + l2.val + carry
            val = ( digit_sum ) % 10 
            carry = ( digit_sum ) // 10
            new_node = ListNode(val)
            if root is None:
                root = new_node
            else:
                prv.next = new_node
            
            prv = new_node 
            l1 = l1.next
            l2 = l2.next
            
        while l1: # l1 is not finish 
            digit_sum = ( l1.val + carry )
            val = ( digit_sum ) % 10 
            carry = ( digit_sum ) // 10 
            new_node = ListNode(val)
            prv.next = new_node
            l1 = l1.next
            prv = new_node
        
        
        while l2:
            digit_sum = ( l2.val + carry )
            val = ( digit_sum ) % 10 
            carry = ( digit_sum ) // 10 
            new_node = ListNode(val)
            prv.next = new_node
            prv = new_node
            l2 = l2.next
        
        if carry > 0:
            new_node = ListNode(carry)
            prv.next = new_node
        
        return root
            
