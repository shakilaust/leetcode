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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL ) return NULL;
        ListNode* curNode = head;
        int len = 1;
        while( curNode->next != NULL) {
            len++;
            curNode = curNode->next;
        }
        
        curNode->next = head;  // make circular link list
        
        ListNode* lastNode = head;
        for( int i = 0 ; i < len - ( k % len ) - 1 ; i++ ) {
            lastNode = lastNode->next;
        }
        head = lastNode->next;
        lastNode->next = NULL;
        return head;
        
    }
};
