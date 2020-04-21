/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* reverseLinkList(ListNode* node) { 
    
    ListNode* head = NULL;
    while( node ) { 
        ListNode* currentNode = new ListNode(node->val);
        if( head == NULL ) head = currentNode;
        else { 
            currentNode->next = head;
            head = currentNode;
        }
        node = node->next;
    }
    return head;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseLinkList(head);
    }
};
