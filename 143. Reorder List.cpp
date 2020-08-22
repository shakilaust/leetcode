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
    void reorderList(ListNode* head) {
        vector < ListNode* > nodes;
        while( head != NULL ) { 
            nodes.push_back(head);
            head = head->next;
        }

        int lft = 0, rgt = nodes.size() - 1;
        int cur = 1, idx;
        ListNode *lastNode = NULL;
        bool foundHead = false;
        while( lft <= rgt ) { 
            if( cur ) { 
                idx = lft;
                lft++;
            } else { 
                idx = rgt;
                rgt--;
            }

           
            ListNode* curNode = nodes[idx];
            curNode->next = NULL;
          //  cout << " curNode " << curNode->val << endl;
            if( foundHead == false ) { 
                foundHead = true;
            } else lastNode->next = curNode;
            
          
            lastNode = curNode;
            cur = 1 - cur;
        }
        
      
    }
};
