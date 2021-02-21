/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> map = new HashMap<>();
        Node newHead = null, prv = null;
        Node curNode = head;
        while( curNode != null ) {
            Node newNode = new Node(curNode.val);
            if( newHead == null ) {
                newHead = newNode;
            } else {
                prv.next = newNode;
            }
            map.put(curNode, newNode);
            curNode = curNode.next;
            prv = newNode;
        }
        curNode = head;
        Node newCurNode = newHead;
        while( curNode != null ) {
            newCurNode.random = map.get(curNode.random);
            curNode = curNode.next;
            newCurNode = newCurNode.next;
        }
        return newHead;
    }
}
