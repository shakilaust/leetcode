class Solution {
public:
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    
   
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        if( rows == 0 ) return 0;
        int cols = board[0].size();
        int ans = 0;
        vector < vector < bool > > visit( rows, vector < bool > ( cols , false) );
        for( int row = 0 ; row < rows; row++ ) {
            for( int col = 0; col < cols; col++ ) {
                if( visit[row][col] || board[row][col] == '.' ) continue;
                queue < pair < int , int > > q;
                q.push({ row, col } );
                visit[row][col] = true;
                ans++;
                while( !q.empty() ) {
                    pair< int, int > now = q.front();
                    q.pop();
                    for( int i = 0 ; i < 4 ; i++ ) {
                        int nx = now.first + dx[i];
                        int ny = now.second + dy[i];
                        if( nx < 0 || nx >= rows || ny < 0 || ny >= cols ) continue;
                        if( visit[nx][ny]  || board[nx][ny] == '.') continue;
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                        
                    }
                    
                }
            }
        }
        return ans;
    }
        
};
