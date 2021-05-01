class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int o = 0, x = 0;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0 ; j < 3 ; j++ ) {
                if( board[i][j] == 'O') o++;
                else if( board[i][j] == 'X' ) x++;
            }
        }
        if( x - o < 0 || x - o > 1 ) return false;
        bool can_x = false, can_o = false;
        for( int element = 0; element < 3; element++ ) {
            // row check
            int row = element;
            if( board[row][0] == board[row][1] && board[row][1] == board[row][2] ) {
                if( board[row][0] == 'O' ) can_o = true;
                else if( board[row][0] == 'X' ) can_x = true;
            }
            // col check;
            int col = element;
            if( board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if( board[0][col] == 'O' ) can_o = true;
                else if( board[0][col] == 'X' ) can_x = true;
            }
            
        }
        if( board[0][0] == board[1][1] && board[1][1] == board[2][2] ) {
            if( board[0][0] == 'O' ) can_o = true;
            else if( board[0][0] == 'X' ) can_x = true;
        }
        if( board[0][2] == board[1][1] && board[1][1] == board[2][0] ) {
            if( board[1][1] == 'O' ) can_o = true;
            else if( board[1][1] == 'X' ) can_x = true;
        }
        
        if( can_x && can_o ) return false;
        else if( o == x && can_x ) return false;
        else if( o != x && can_o ) return false;
        return true;
    }
};
