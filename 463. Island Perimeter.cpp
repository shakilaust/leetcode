

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        if( rows == 0 ) return 0;
        int cols = grid[0].size();
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 0;
        for( int row = 0 ; row < rows; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                int cnt = grid[row][col] ? 4 : 0;
                if( cnt > 0 ) {
                    for( int i = 0 ; i < 4 ; i++ ) {
                        int nxtRow = row + dx[i];
                        int nxtCol = col + dy[i];
                        if( nxtRow < 0 || nxtCol < 0 || nxtRow >= rows || nxtCol >= cols ) continue;
                        if( grid[nxtRow][nxtCol] ) cnt--;
                    }
                }
                ans += cnt;
            }
        }
        return ans;
    }
};
