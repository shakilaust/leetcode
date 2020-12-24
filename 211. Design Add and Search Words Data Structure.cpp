struct Trie{
    Trie* child[26];
    bool isFinish;
    Trie() {
        for( int i = 0 ; i < 26 ; i++ ) {
            child[i] = NULL;
        }
        isFinish = false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* root = NULL;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curNode = root;
        for( char ch: word ) {
            int idx = ch - 'a';
            if( curNode->child[idx] == NULL ) {
                curNode->child[idx] = new Trie();
            }
            curNode = curNode->child[idx];
        }
        curNode->isFinish = true;
    }
    
    
    bool dfs(Trie* curNode, string &word, int idx) {
        if( idx == word.size()) {
            return curNode->isFinish;
        }
        
        if( word[idx] == '.' ) {
            
            for( int i = 0 ; i < 26 ; i++ ) {
                if( curNode->child[i] != NULL ) {
                    if( dfs( curNode->child[i], word, idx + 1 ) == true ) return true;
                }
            }
            
            return false;
            
        } else {
            int childIdx = word[idx] - 'a';
            if( curNode->child[childIdx] == NULL ) return false;
            return dfs( curNode->child[childIdx], word, idx + 1 );
        }
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
