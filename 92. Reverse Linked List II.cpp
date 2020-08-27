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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode* dummy = new ListNode(0);
       dummy->next = head;
       ListNode* pre = dummy;
       while( --m ) { 
           pre = pre->next;
           n--;
       }
       ListNode* start = pre->next;
       ListNode* then = start->next;
        
       while( --n ) { 

        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next;
      }
        
      return dummy->next;
    }
};
