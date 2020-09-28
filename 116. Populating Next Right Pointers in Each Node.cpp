/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue < Node* > q;
        if( root == NULL ) return root;
        q.push(root);
        while(!q.empty()) { 
            int sz = q.size();
            Node* nxt = NULL;
            while( sz-- ) { 
                Node* now = q.front();
                q.pop();
                now->next = nxt;
                if( now->right ) q.push(now->right);
                if( now->left ) q.push(now->left);
                nxt = now;
            }
        }
        return root;
    }
};
