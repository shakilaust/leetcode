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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* curNode, *prvNode = NULL;
        while( head && head->next ) {
            curNode = new ListNode(head->next->val);
            curNode->next =new ListNode(head->val);
            if( prvNode == NULL ) {
                newHead = curNode;
            } else {
                prvNode->next = curNode;
            }
            curNode = curNode->next;
            prvNode = curNode;
            head = head->next->next;
        }
        
        if( head ) {
            if( prvNode ) {
                prvNode->next = head;
            } else {
                newHead = head;
            }
        }
        
        return newHead;
    }
};
