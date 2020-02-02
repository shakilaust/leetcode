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

    ListNode* _addOne(ListNode *l1, int carry) { 
        
        if(l1 == NULL && carry == 0 ) return NULL;
        ListNode* cur = new ListNode(carry);
        if( l1 != NULL ) { 
            cur->val = ( cur->val + l1->val );
        }
   
        carry = ( cur->val / 10 );
        cur->val = ( cur->val % 10 );
        cur->next = _addOne( l1 ? l1->next : l1 , carry );
        
        return cur;
    }
   
    ListNode* plusOne(ListNode* head) {
        return reverseLinkList(_addOne(reverseLinkList(head), 1));
    }
};
