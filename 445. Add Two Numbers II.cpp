/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkList(ListNode *node) {
        ListNode* head = NULL;
        while( node ) { 

            ListNode* n = new ListNode(node->val);
            n->next = head;
            head = n;
            node = node->next;
        }
        return head;
    }
    ListNode* _addTwoNumbers(ListNode *l1, ListNode *l2, int carry) { 
        
        if(l1 == NULL && l2 == NULL && carry == 0 ) return NULL;
        ListNode* cur = new ListNode(carry);
        if( l1 != NULL ) { 
            cur->val = ( cur->val + l1->val );
        }
        if( l2 != NULL ) { 
            cur->val = ( cur->val + l2->val );
        }
        carry = ( cur->val / 10 );
        cur->val = ( cur->val % 10 );
        cur->next = _addTwoNumbers( l1 ? l1->next : l1 , l2 ? l2->next : l2, carry );
        
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverseLinkList(_addTwoNumbers(reverseLinkList(l1), reverseLinkList(l2), 0));
    }
};
