class Solution {
public:
   void printBoard( vector < string > &board) {
       for( string now: board ) {
           cout << now << endl;
       }
   }
    vector<string> gameBoard(vector < vector< int >>& moves) {
        vector<string> board;
        for( int i = 0 ; i < 3 ; i++ ) {
            string field = "";
            for( int j = 0 ; j < 3 ; j++ ) {
                field += ' ';
            }
            board.push_back(field);
        }
        char ch = 'A';
        for( vector< int> move: moves) {
            board[move[0]][move[1]] = ch;
            if( ch == 'A' ) {
                ch = 'B';
            } else ch = 'A';
        }
        return board;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> board = gameBoard(moves);
        string ans = "";
        bool pendingPossible = false;
       // printBoard(board);
        for( int row = 0 ; row < 3 ; row++ ) {
            int f = 0;
            int s = 0;
            for( int col = 0 ; col < 3 ; col++ ) {
                if( board[row][col] == 'A' ) f++;
                else if( board[row][col] == 'B' ) s++;
                else if( board[row][col] == ' ' ) pendingPossible = true;
            }
            if( f == 3 ) return "A";
            else if( s == 3 ) return "B";
            int ff = 0;
            int ss = 0;
            for( int y = row, x = 0 ; x < 3 ; x++) {
                if( board[x][y] == 'A' ) ff++;
                else if( board[x][y] == 'B' ) ss++;
                else if( board[x][y] == ' ' ) pendingPossible = true;
              
               
            }
            
            if( ff == 3 ) return "A";
            else if( ss == 3 ) return "B";
        //    cout << " col " << row << " ss " << ss << " ff " << ff << endl;
            
        }
        
        if( board[0][0] == board[1][1] && board[1][1] == board[2][2] ) {
            if( board[0][0] == 'A' ) {
                return "A";
            }
            else if( board[1][1] == 'B' ) {
                return "B";
            }
        }
          if( board[0][2] == board[1][1] && board[1][1] == board[2][0] ) {
            if( board[1][1] == 'A' ) {
                return "A";
            }
            else if( board[1][1] == 'B' ) {
                return "B";
            }
        }
        if( pendingPossible ) return "Pending";
        return "Draw";
        
    }
};
