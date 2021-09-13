# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def reverseList(head: Optional[ListNode]) -> Optional[ListNode]:
        root = None
        prv = None
        while head:
            curNode = ListNode(head.val)
            root = curNode
            root.next = prv
            prv = curNode
            head = head.next
        
        return root
class Solution:
    
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        reverse_list = reverseList(head)
        while head and reverse_list:
            if head.val != reverse_list.val:
                return False
            head = head.next
            reverse_list = reverse_list.next
        
        if head or reverse_list:
            return False
        
        return True
