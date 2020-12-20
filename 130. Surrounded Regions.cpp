class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if( rows <= 2 ) return;
        int cols = board[0].size();
        vector < vector < bool > > visits( rows + 1, vector < bool > ( cols + 1 , false) );

        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( col > 0 && col < cols - 1 && row != 0 && row != rows - 1 ) continue;
                visits[row][col] = true;
                if( board[row][col] == 'O') {
                    queue < pair< int, int > > q;
                    q.push({row, col});
                    visits[row][col] = true;
                    while( !q.empty()) {
                        int dx[] = {1, -1, 0, 0};
                        int dy[] = {0, 0, 1, -1};
                        auto now = q.front();
                        q.pop();
                        for( int i = 0 ; i < 4 ; i++ ) {
                            int nxtRow = dx[i] + now.first;
                            int nxtCol = dy[i] + now.second;
                            if( nxtRow >= 0 && nxtRow < rows && nxtCol >= 0 && nxtCol < cols ) {
                                if( board[nxtRow][nxtCol] == 'O' && visits[nxtRow][nxtCol] == false) {
                                    visits[nxtRow][nxtCol] = true;
                                    q.push({nxtRow, nxtCol});
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for( int row = 1 ; row < rows - 1; row++ ){
            for( int col = 1 ; col < cols - 1 ; col++ ) {
                if( visits[row][col] == false ) {
                    board[row][col] = 'X';
                }
            }
        }
       
    }
};
