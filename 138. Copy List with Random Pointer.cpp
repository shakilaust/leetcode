/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* headOfCopy = NULL, *prv = NULL;
        unordered_map <Node*, Node*> ump;
        Node* cur = head;
        while( cur != NULL ) { 
            Node* curNode = new Node(cur->val);
            
            if( prv == NULL ) { 
                headOfCopy = curNode;
            } else { 
                prv->next = curNode;
            }
            prv = curNode;
            ump[cur] = curNode;
            cur = cur->next;
        }
        cur = head;
        Node* copyCur = headOfCopy;
        while( cur != NULL ) { 
            copyCur->random = ump[cur->random];
            cur = cur->next;
            copyCur = copyCur->next;
        }
        return headOfCopy;
    }
};
