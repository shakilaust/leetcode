int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1 };


bool isInsideBoard( int x, int y, int row, int column ) { 

    return x >= 0 && x < row && y >= 0 && y < column;
}




class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int column = board[0].size();
      
        for( int i = 0 ; i < row; i++ ) { 
            
            for( int j = 0 ; j < column ; j++ ) { 
        
                int livingCells = 0;
                for( int k = 0 ; k < 8 ; k++ ) { 
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if(isInsideBoard(x, y, row, column) && (board[x][y] == 1 || board[x][y] == -1 )) { 
                        livingCells += 1;
                    }
                }
                if(board[i][j] == 0 ) {
                    board[i][j] = ( livingCells == 3 ? 2 : 0 );
                } else {
                    if( livingCells < 2 ) board[i][j] = -1;
                    else if( livingCells > 3 ) board[i][j] = -1;

                }
            }

        }
        for( int i = 0 ; i < row ; i++ ) { 

            for( int j = 0 ; j < column ; j++ ) board[i][j] = board[i][j] > 0 ? 1 : 0;
        }
        
    }
};
