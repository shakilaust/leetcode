# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        
        visited = dict() # key: ListNode, val: True 
        while head:
            if head in visited:
                return True # there is cycle present in the linked List 
            visited[head] = True
            head = head.next
        
        return False
        
