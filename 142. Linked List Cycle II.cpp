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
    ListNode *detectCycle(ListNode *head) {
        unordered_map< ListNode*, bool> visit;
        while(head) { 

            if( visit[head] ) return head;
            visit[head] = true;
            head = head->next;
        }
        return NULL;
    }
};
