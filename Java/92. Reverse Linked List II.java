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
    public ArrayList reverseArrayList(ArrayList<ListNode> inp, int m, int n) {
        ArrayList<ListNode> newArrayList = new ArrayList<>();
        for( int i = 0 ; i < m ; i++ ) {
            newArrayList.add(inp.get(i));
        }
        for( int i = n ; i >= m ; i-- ) {
            newArrayList.add(inp.get(i));
        }

        for( int i = n + 1 ; i < inp.size(); i++ ) {
            newArrayList.add(inp.get(i));
        }

        return newArrayList;
    }
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ArrayList<ListNode> inp = new ArrayList<> ();
        m--;
        n--;
        ListNode cur = head;
        while(cur != null) {
            inp.add(cur);
            cur = cur.next;
        }
        inp = reverseArrayList(inp, m, n);
        ListNode newHead = null;
        ListNode prv = null;
        for( int i = 0 ; i < inp.size(); i++ ) {
            cur = inp.get(i);
            cur.next = null;
            if( newHead == null ) {
                newHead = cur;
            } else {
                prv.next = cur;
            }
            prv = cur;
        }
        
        return newHead;
    }
}
