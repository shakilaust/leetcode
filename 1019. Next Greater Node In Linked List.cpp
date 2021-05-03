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
    vector<int> nextLargerNodes(ListNode* head) {
       vector < int > values;
        while( head ) {
            values.push_back( head->val );
            head = head->next;
        }
        stack < int > st;
        for( int i = values.size() - 1 ; i >= 0 ; i-- ) {
            while( !st.empty() && st.top() <= values[i] ) {
                st.pop();
            }
            int sv = values[i];
            values[i] = st.empty() ? 0 : st.top();
            st.push( sv );
        }
        return values;
    }
    
};
