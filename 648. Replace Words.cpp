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

void InsertIntoTrie(TrieNode *root, string &word) { 

    TrieNode* cur = root;
    for( int i = 0 ; i < word.size() ; i++ ) {
        int idx = word[i] - 'a';
        if( cur->nxt[idx] == NULL ) { 
            cur->nxt[idx] = new TrieNode();
        }
        
        cur = cur->nxt[idx];

    }
    
    cur->isWord = true;
}

pair < string, bool > shortestPrefix(TrieNode *root, string &word) {

    TrieNode* cur = root;
    string prefix = "";
    for( int i = 0 ; i < word.size() && cur->isWord == false ; i++ ) { 
        int idx = word[i] - 'a';
        if( cur->nxt[idx] == NULL ) return {prefix, false};
        prefix += word[i];
        cur = cur->nxt[idx];
    }
    return {prefix, cur->isWord};
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string ans = "";
        string word;
        stringstream st(sentence);
        TrieNode* root = new TrieNode();
        for( string word: dict ) InsertIntoTrie(root, word);
        bool firstWord = false;
        while( st >> word ) { 

            pair< string, bool > isPossible = shortestPrefix(root, word );
            if( firstWord ) ans += " ";
            firstWord = true;
            if( isPossible.second ) {
                ans += isPossible.first;
            } else { 
                ans += word;
            }
        }
        
        return ans;
    }
};
