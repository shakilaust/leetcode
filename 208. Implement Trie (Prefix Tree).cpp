class Trie {
private:
struct TrieNode{ 
    bool isWord;
    TrieNode* nxt[26];
    
    TrieNode(){
        isWord = false;
        for( int i = 0 ; i < 26 ; i++ ) { 
            nxt[i] = NULL;
        }
        
    }
};

TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for( char ch: word ) { 
            int idx = ch - 'a';
            if( cur->nxt[idx] == NULL) { 
                cur->nxt[idx] = new TrieNode();
            }   
            cur = cur->nxt[idx];
        }
        
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for( char ch: word ) { 
            int idx = ch - 'a';
            if( cur->nxt[idx] == NULL ) { 
               return false;
            }   
            cur = cur->nxt[idx];
        }
        
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for( char ch: prefix ) { 
            int idx = ch - 'a';
            if( cur->nxt[idx] == NULL ) { 
               return false;
            }   
            cur = cur->nxt[idx];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
