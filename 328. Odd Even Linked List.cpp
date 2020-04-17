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
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL ) return head;
        ListNode* node = head;
        ListNode* oddHead = NULL;
        ListNode* evenHead = NULL;
        ListNode* odd = NULL;
        ListNode* even = NULL;
        bool forEven = false;
        while( node ) { 
            ListNode* curNode = new ListNode(node->val);
            if(forEven) { 
                if(evenHead == NULL ) { 
                    evenHead = curNode;
                    even = curNode;
                } else { 
                    even->next = curNode;
                    even = even->next;
                }
            } else { 
                
                if(oddHead == NULL ) { 
                    oddHead = curNode;
                    odd = curNode;
                 } else { 
                    odd->next = curNode;
                    odd = odd->next;
                }
        
            }
            
            forEven = !forEven;
            
            node = node->next;
        }
    odd->next = evenHead;
    return oddHead;
    }
};
