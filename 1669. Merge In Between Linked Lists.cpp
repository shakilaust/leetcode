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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* A = NULL;
        ListNode* B = NULL;
        ListNode* prv = NULL;
        ListNode* curNode = list1;
        while( curNode != NULL ) {
            if( a == 0 ) {
                A = prv;
            } else if( b == -1 ) {
                B = curNode;
            }
            a--;
            b--;
            prv = curNode;
            curNode = curNode->next;
        }
        
        ListNode* lstNode = NULL;
        curNode = list2;
        while( curNode ) {
            lstNode = curNode;
            curNode = curNode->next;
        }
        
        ListNode* head = NULL;
        if( A == NULL && B == NULL ) return list2;
        else if( A == NULL && B != NULL ) {
            head = list2;
            lstNode->next = B;
            return head;
        } else if( list2 == NULL ) {
            return list1;
        } else {
            A->next = list2;
            lstNode->next = B;
            return list1;
        }
        
        
    }
};
