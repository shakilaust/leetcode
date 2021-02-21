/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        ArrayList<Integer> nodes = new ArrayList<>();
        ListNode curNode = head;
        while( curNode != null ) {
            nodes.add(curNode.val);
            curNode = curNode.next;
        }
        Collections.sort(nodes);
        ListNode newHead = null, prv = null;
        for( int x: nodes) {
            ListNode newNode = new ListNode(x);
            if( newHead != null ) {
                prv.next = newNode;
            } else newHead = newNode;
            prv = newNode;
        }
        return newHead;
    }
}
