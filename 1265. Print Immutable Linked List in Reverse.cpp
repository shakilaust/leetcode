/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack < ImmutableListNode > st;
        st.push(*head);
        while( true ) { 
            head = head->getNext();
            if( head == NULL ) break;
            st.push(*head);
        }
        while(!st.empty()) {
            st.top().printValue();
            st.pop();
        }
    }
};
