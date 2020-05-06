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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode*, bool> visit;
        
        while(headA != NULL ) { 
            visit[headA] = true;
            headA = headA->next;
        }
        ListNode* ans = NULL;
        while( headB != NULL ) { 
            if( visit[headB] == true ) { 
                ans = headB;
                break;
            }
            
            headB = headB->next;
        }
        
        return ans;
    }
};
