const int ALPHABAT = 26;
int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1, -1};

int rows, columns;

bool isInside( int row, int col) { 
    if( row >= 0 && row < rows && col >= 0 && col < columns ) return true;
    return false;
}

struct Trie{
    
    string word;
    bool isFinish;
    Trie* child[ALPHABAT];
    
    Trie(){ 
        for( int i = 0 ; i < ALPHABAT ; i++ ) child[i] = NULL;
        word = "";
        isFinish = false;
    }

};


Trie* InsertIntoTrie(vector< string> &words) { 

    Trie* root = new Trie();
    for( string word: words) { 
        Trie* current = root;
        for( char ch: word) { 
            int idx = ch - 'a';
            if( current->child[idx] == NULL ) { 
                current->child[idx] = new Trie();
            }
            current = current->child[idx];
        
        }
        current->word = word;
        current->isFinish = true;
    }
    return root;

}


void dfs( vector<vector<char>>& board, int x, int y, Trie* current, vector<string> &ans) { 

    char ch = board[x][y];
    if( ch == '#' || current->child[ch-'a'] == NULL ) return;
    current = current->child[ch-'a'];
    if( current->isFinish ) { 
        current->isFinish = false;
        ans.push_back(current->word);
    }
    board[x][y] = '#';
    for( int i = 0 ; i < 4 ; i++ ) { 
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( isInside(nx, ny) ) { 
            dfs(board, nx, ny, current, ans);
        }
    }
    
    board[x][y] = ch;

}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector < string > ans;
        rows = board.size();
        columns = board[0].size();
        Trie* root = InsertIntoTrie(words);
        for( int i = 0 ; i < rows ; i++ ) { 
            for( int j = 0 ; j < columns ; j++ ) { 
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};
