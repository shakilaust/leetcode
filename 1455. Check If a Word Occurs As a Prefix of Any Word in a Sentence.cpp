
class Trie{
    public:
    struct Node{
        Node* child[26];
        int sequenceNumber;
        Node(int seq) {
            for( int i = 0 ; i < 26  ; i++ ) {
                child[i] = nullptr;
            }
            sequenceNumber = seq;
        }
    };
    Node* root = nullptr;
    Trie() {
        root = new Node(-1);
    }
    
    void getInsertIntoTrie(string word, int id) {
        Node* curNode = this->root;
        for( int i = 0 ; i < word.size() ; i++ ) {
            int idx = word[i] - 'a';
            if( curNode->child[idx] == nullptr ) {
                curNode->child[idx] = new Node(id);
            }
            curNode = curNode->child[idx];
        }
    }
    
    int isPrefix(string word) {
        Node* curNode = this->root;
        for( int i = 0 ; i < word.size() ; i++ ) {
            int idx = word[i] - 'a';
            if( curNode->child[idx] == nullptr ) {
                return -1;
            }
            curNode = curNode->child[idx];
            cout << " now " << curNode->sequenceNumber << endl;
        }
        return curNode->sequenceNumber;
    }
    
    
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        Trie* trie = new Trie();
        stringstream ss(sentence);
        string word;
        int idx = 1;
        while( ss >> word ) {
            trie->getInsertIntoTrie(word, idx++);
        }
        
        return trie->isPrefix(searchWord);
        
    }
};
