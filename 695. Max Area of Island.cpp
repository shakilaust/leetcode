class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int dx[] = { 1, -1, 0, 0};
        int dy[] = { 0, 0, 1, -1};
        int rows = grid.size();
        if( rows == 0 ) {
            return ans;
        }
        int cols = grid[0].size();
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( grid[row][col] ) {
                    int cnt = 1;
                    queue < int > x, y;
                    x.push(row);
                    y.push(col);
                    grid[row][col] = 0;
                    while( !x.empty() ) {
                        int curRow = x.front();
                        int curCol = y.front();
                        x.pop();
                        y.pop();
                        for( int i = 0 ; i < 4 ; i++ ) {
                            int nxtRow = curRow + dx[i];
                            int nxtCol = curCol + dy[i];
                            if( nxtRow >= 0 && nxtRow < rows ) {
                                if( nxtCol >= 0 && nxtCol < cols ) {
                                    if( grid[nxtRow][nxtCol] == 1 ) {
                                        x.push(nxtRow);
                                        y.push(nxtCol);
                                        cnt++;
                                        grid[nxtRow][nxtCol] = 0;
                                    }
                                }
                            }
                        }
                    }
                    ans = max( ans, cnt);
                }
            }
        }
        return ans;
    }
};
