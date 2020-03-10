int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isPossible( int x, int y, int row, int column, vector< vector< bool> >& vis) {
    if( x >= 0 && x < row && y >= 0 && y < column && vis[x][y] == false ) {
        return true;
    }
    return false;
}

bool dfs( int x, int y, int row, int column, vector< vector< bool> >& vis, vector<vector<char>>& board, string &word, int matchSoFar) {
    
    if(matchSoFar == word.size() ) {
        return true;
    }
    vis[x][y] = true;
    
    for( int i = 0 ; i < 4 ; i++ ) { 
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isPossible( nx, ny, row, column, vis)) {
            if(board[nx][ny] == word[matchSoFar]){
                if(dfs(nx, ny, row, column, vis, board, word, matchSoFar + 1 ) == true ) return true;
            }
        }

    }
    
    
    vis[x][y] = false;
    return false;

}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int column = board[0].size();
        vector < vector< bool > > vis( row , vector < bool > (column , false));
        for( int i = 0 ; i < row ; i++ ) { 
            for( int j = 0 ; j < column ; j++ ) { 
                if(board[i][j] == word[0] && dfs(i, j, row, column, vis, board, word, 1 )) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
