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
    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead = NULL;
        ListNode* prvNode = NULL;
        ListNode* currentNode = head;
        while( currentNode ) {
            ListNode* now = new ListNode(currentNode->val);
            if( currentNode->val < x ) {
                if( newHead == NULL ) {
                    newHead = now;
                } else {
                    prvNode->next = now;
                }
                prvNode = now;
            }
            
            currentNode = currentNode->next;
        }
        
        currentNode = head;
        while( currentNode ) {
            ListNode* now = new ListNode(currentNode->val);
                if( currentNode->val >= x ) {
                    if( newHead == NULL ) {
                        newHead = now;
                    } else {
                        prvNode->next = now;
                    }
                    prvNode = now;
                }

                currentNode = currentNode->next;
            }
        return newHead;
    }
};
