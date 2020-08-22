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
    ListNode* sortList(ListNode* head) {
        vector < int > inp;
        while( head != NULL ) { 
            inp.push_back(head->val);
            head = head->next;
        }
        
        sort( inp.begin(), inp.end());
        
        ListNode* newHead = NULL, *lastNode = NULL;
        for( int i = 0 ; i < inp.size();i++ ) { 
            ListNode* newNode = new ListNode(inp[i]);
            if( i ) { 
                lastNode->next = newNode;
            } else newHead = newNode;
            lastNode = newNode;
        }
        
        return newHead;
    }
};
