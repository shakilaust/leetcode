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
    ListNode* result(ListNode* l1, ListNode* l2, int carry) { 
        if( l1==NULL && l2 == NULL && carry == 0 ) return NULL;
        int value = carry;
        if( l1 != NULL ) value = value + l1->val;
        if( l2 != NULL ) value = value + l2->val;
        carry = value / 10;
        value = value % 10;
        ListNode* current = new ListNode(value);
        current->next = result( l1 ? l1->next : l1 , l2 ? l2->next : l2, carry );
        return current;
    
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return result(l1, l2, 0);
    }
};
