
class Solution {
public:
    
    vector < vector < bool > > visits;
    int rows, cols;
    vector < int > dx{1,-1, 0, 0};
    vector < int> dy{0,0, 1,-1};
    
    bool ok( int row, int col ) {
        if( row >= 0 && row < rows && col >= 0 && col < cols ) {
            if( visits[row][col] == false ) return true;
            
        }
        return false;
    }
    void dfs( int x, int y, vector<vector<int>>& grid) {
        visits[x][y] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if( ok( nx, ny) && grid[nx][ny] == 0 ) {
                dfs( nx, ny, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        if( rows == 0 ) {
            return 0;
        }
        cols = grid[0].size();
        visits.resize(rows);
        for( int row = 0 ; row < rows ; row++ ) {
            visits[row].resize( cols, false );
        }
        for( int row = 0, col = 0 ; col < cols ; col++ ) {
            if( grid[row][col] == 0 && visits[row][col] == false ) {
                dfs( row, col, grid );
            }
        }
        for( int col = cols - 1, row = 0 ; row < rows ; row++ ) {
            if( grid[row][col] == 0 && visits[row][col] == false ) {
                dfs( row, col, grid );
            }
        }
        
        for( int row = rows - 1 , col = 0 ; col < cols ; col++ ) {
            if( grid[row][col] == 0 && visits[row][col] == false ) {
                dfs( row, col, grid );
            }
        }
        for( int row = 0, col = 0 ; row < rows; row++ ) {
            if( grid[row][col] == 0 && visits[row][col] == false ) {
                dfs( row, col, grid );
            }
        }
        
        int ans = 0 ;
        for( int row = 0 ; row < rows ; row++ ) {
            for(int col = 0 ; col < cols ; col++ ) {
                if( grid[row][col] == 0 && visits[row][col] == false ) {
                    ans++;
                    dfs( row, col, grid );
                }
            }
        }
        
        return ans;
    }
};
