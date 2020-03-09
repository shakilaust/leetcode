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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *head = NULL;
        ListNode *prv = NULL;
        bool update = true;
        while(update) { 
            update = false;
            int idx = -1;
            
            for( int i = 0 ; i < lists.size(); i++ ) { 

                if(lists[i] != NULL ) { 
                    if( idx == -1 || lists[idx]->val > lists[i]->val ) {
                        idx = i;
                        update = true;
                    }
                }
            }
            
            if( idx != -1 ) {
                ListNode* node = new ListNode(lists[idx]->val);
                if( head == NULL ) { 
                    head = node;
                    prv = head;
                } else {
                    prv->next = node;
                    prv = prv->next;

                }

                    lists[idx] = lists[idx]->next;
            }
            
            

        }
        return head;
    }
};
