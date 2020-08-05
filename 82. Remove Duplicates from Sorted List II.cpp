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
        ListNode* newHead = NULL;
        ListNode* curNode = NULL, *prvNode = NULL;
        while(head != NULL ) { 
            
            int value = head->val;
            bool same = false;
         
            while( head && head->next && head->val == head->next->val ) { 
                head = head->next;
                same = true;
            }
            
            if( head == NULL ) break;
            
            if( same && head->val == value ) { 
                head = head->next;
                continue;
            }

        
            curNode = new ListNode(head->val);

            
            
            if( prvNode != NULL ) { 
                prvNode->next = curNode;
            } else { 
                newHead = curNode;
            }
            
            prvNode = curNode;
            head = head->next;
        }
         return newHead;
    }
    
   
};
