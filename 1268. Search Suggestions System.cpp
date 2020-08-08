struct TrieNode{ 
    TrieNode* nextChild[26];
    vector < string > words;
    TrieNode() {
        for( int i = 0 ; i < 26 ; i++ ) { 
            nextChild[i] = NULL;
        }
        words.clear();
    }
};


class Solution {
    
    
TrieNode *root = new TrieNode();
    
void insertIntoTrie(string word) { 
    
    TrieNode* currentNode = root;
    for( int i = 0 ; i < word.size() ; i++ ) { 
        int idx = word[i] - 'a';
        if( currentNode->nextChild[idx] == NULL ) { 
             currentNode->nextChild[idx] = new TrieNode();
        }
        
        currentNode = currentNode->nextChild[idx];
        currentNode->words.push_back(word);
    }

}
    
vector < string > searchWordInTrie( string now ) { 

    TrieNode* currentNode = root;
    vector < string > dummy;
    for( int i = 0 ; i < now.size() ; i++ ) { 
        int idx = now[i] - 'a';
        if( currentNode->nextChild[idx] == NULL ) return dummy;
        currentNode = currentNode->nextChild[idx];
    }
    
    return currentNode->words;
}

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for( string product: products) { 
            insertIntoTrie(product);
        }
        
        vector < vector < string > > answer;
        string now = "";
        for( int i = 0 ; i < searchWord.size() ; i++ ) { 
            now += searchWord[i];
            vector < string > possible = searchWordInTrie(now);
            if( possible.size() > 0 ) { 
                sort( possible.begin(), possible.end());
                if( possible.size() > 3 ) { 
                    possible.resize(3);
                }
            }
            
            answer.push_back(possible);
            
        }
        
        return answer;
        
    }
};
