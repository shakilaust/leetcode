/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseLinkList(ListNode *node) {
        ListNode* head = NULL;
        while(node) {
           
            ListNode* currentNode = new ListNode(node->val);
            currentNode->next = head;
            node = node->next;
            head = currentNode;
        }
        return head;
}
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        head = reverseLinkList(head);
        
        if( n == 1 ) { 
            head = head->next;
            return reverseLinkList(head);
        } else {
            n--;
        }
        ListNode* node = head;
        while( n > 1 && node) { 
            node = node->next;
            n--;
        }
        
        if( n == 1 ) { 
            
            node->next = ( node->next ? node->next->next : NULL );
        }
        
        return reverseLinkList(head);
    }
};
