/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      
        ListNode* lastNode = NULL;
        ListNode* newHead = NULL;
        while( head != NULL ) { 
            ListNode* curNode = new ListNode(head->val);
            if( newHead == NULL ) { 
                newHead = curNode;
                lastNode = curNode;
            } else { 
                if( lastNode->val != curNode->val ) { 
                    lastNode->next = curNode;
                    lastNode = curNode;
                }
            }
            
            head = head->next;
        }
        
        return newHead;
    }
};
