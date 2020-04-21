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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* node = NULL;
        int val;
        while( l1 != NULL || l2 != NULL ) {
            
           if( l1 && l2 && l1->val <= l2->val ) { 
                val = l1->val;
                l1 = l1->next;
           } else if( l1 && l2 && l1->val > l2->val ) { 
                val = l2->val; 
                l2 = l2->next;
          } else if( l1 ) { 
                val = l1->val;
                l1 = l1->next;
          } else { 
                val = l2->val;
                l2 = l2->next;
          }
          ListNode* curNode = new ListNode(val);
          if( node ) { 
                node->next = curNode;
                node = node->next;
          } else { 
                node = curNode;
                head = node;
          }
        }
    return head;
    }
};
