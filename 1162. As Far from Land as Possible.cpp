int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        if( rows == 0 ) return -1;
        int cols = grid[0].size();
        
        vector < vector < bool > > visits( rows , vector < bool > ( cols, false ) );
        vector < vector < int > > cost( rows, vector < int> ( cols, INT_MAX));
        queue < pair < int, int > > q;
        for( int row = 0; row < rows; row++ ) {
            for( int col = 0 ; col < cols; col++ ) {
                if( grid[row][col] == 1 ) {
                    visits[row][col] = true;
                    cost[row][col] = 0;
                    q.push({row, col});
                }
            }
        }
        int ans = -1;
        while( !q.empty()) {
            pair< int, int> cur = q.front();
            q.pop();
            int c = cost[cur.first][cur.second];
            ans = max( c, ans );
         
            
            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = dx[i] + cur.first;
                int ny = dy[i] + cur.second;
                if( nx >= 0 && nx < rows && ny >= 0 && ny < cols && visits[nx][ny] == false) {
                    if( grid[nx][ny] == 0 ) {
                        cost[nx][ny] = c + 1;
                        visits[nx][ny] = true;
                        q.push( {nx, ny});
                    }
                }
            }
        }
        
        return ans > 0 ? ans : -1 ;
    }
};
