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
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode* resultHead = NULL;
        ListNode* currentList = head;
        ListNode* lastItemFromChain = NULL;
        int itemSofar = 0;
        stack < ListNode* > st;
        
        while(currentList) { 
            
         
            if(st.empty() && lastItemFromChain != NULL) { 
                    
                    lastItemFromChain->next = currentList;
            }
            
            st.push(currentList);
            if( st.size() == k ) { // need reverse
                
                ListNode *dummyHead = NULL,* prv = NULL;
                while(!st.empty()) { 

                    ListNode* cur = new ListNode(st.top()->val);
                    st.pop();
                    if( dummyHead == NULL ) { 
                        
                        dummyHead = cur;

                     } else { 
                        prv->next = cur;

                    }
                    prv = cur;
                    
                }
                
                if( resultHead == NULL ) { 
                    resultHead = dummyHead;

                } else { 
                    lastItemFromChain->next = dummyHead;
                }
                
                lastItemFromChain = prv;

                
            }
            
            currentList = currentList->next;
            
            
        }
        
        
        return resultHead ? resultHead : head;
    }
};
