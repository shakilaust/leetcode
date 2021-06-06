/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> graph;
    
    void dfs(Node* curNode ) {
        Node* newNode = new Node(curNode->val);
        graph[curNode] = newNode;
        for( int i = 0 ; i < curNode->neighbors.size() ; i++ ) {
            if( graph.find( curNode->neighbors[i]) == graph.end()) {
                dfs(curNode->neighbors[i]);
            }
        }
        for( int i = 0 ; i < curNode->neighbors.size() ; i++ ) {
            newNode->neighbors.push_back( graph[ curNode->neighbors[i]]);
        }
    }
    Node* cloneGraph(Node* node) {
        if( node == NULL ) return NULL;
        dfs( node );
        return graph[node];
    }
};
