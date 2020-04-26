vector < char > possibleNumbers( int row, int col, vector<vector<char>>& board ) {
  
      vector < bool > possible( 10 , true );
      vector < char > options;

       for( int i = 0 ; i < 9 ;  i++ ) { 
            if( i == col || board[row][i] == '.' ) continue;
            possible[board[row][i] - '0'] = false;
        }
  
       for( int i = 0 ; i < 9 ;  i++ ) { 
            if( i == row || board[i][col] == '.' ) continue;
            possible[ board[i][col] - '0'] = false;
        }
       for( int curRow = ( row / 3 ) * 3, i = 0 ; i < 3 ; i++, curRow++ ) { 
            for( int curCol = ( col / 3 ) * 3 , j = 0 ; j < 3 ; j++, curCol++ ) { 
                  if( curRow == row && curCol == col ) continue;
                  if( board[curRow][curCol] == '.' ) continue;
                  possible[board[curRow][curCol] - '0' ] = false;
            }
         }
  
     for( int i  = 1 ; i <= 9 ; i++ ) if( possible[i] == true ) options.push_back(i + '0');
     return options;
  
}

bool dfs( int row, int col , vector<vector<char>>& board ) { 

  if( row == 9 ) return true;
  if( col == 9 ) return dfs( row + 1 , 0 , board);
  if( board[row][col] == '.' ) {
        vector < char > options = possibleNumbers(row, col, board );
        for( char option: options ) { 
              board[row][col] = option;
              if( dfs( row , col + 1 , board ) == true ) return true;
             
          }
         board[row][col] = '.';
        return false;
  }
   return dfs( row , col + 1 , board );

}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0, 0, board);
        
    }
};
