/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    const cached = new Map();
    while(headA) {
        cached.set(headA, true);
        headA = headA.next;
    }
    let ans = null;
    while( headB ) {
        if( cached.has(headB) ) {
            ans = headB;
            break;
        }
        headB = headB.next;
    }
    return ans;
};
