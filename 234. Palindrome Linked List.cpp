/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseLinkList(ListNode* node) { 

    ListNode* head = NULL;
    while( node ) { 
        ListNode* curNode = new ListNode(node->val);
        if( head ) { 
            curNode->next = head;
            head = curNode;
        } else head = curNode;
        node = node->next;

    }
    return head;
}

bool checkPalindrome(ListNode* front, ListNode* back) { 
    ListNode* fast = front;
    while( fast  ) { 

        if( front->val != back->val ) return false;
        front = front->next;
        back = back->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
   
    return true;

}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* reverseHead = reverseLinkList(head);
        return checkPalindrome(head, reverseHead);
    }
};
