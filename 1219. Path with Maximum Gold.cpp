int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int rows, cols;

int dfs( int row, int col, vector<vector<int>>& grid) {
    int now = grid[row][col];
    grid[row][col] = 0;
    int cnt = 0;
    for( int i = 0 ; i < 4 ; i++ ) {
        int nx = row + dx[i];
        int ny = col + dy[i];
        if( nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] > 0 ) {
            cnt = max( cnt, dfs( nx, ny, grid ) );
        }
    }
    
    
    
    grid[row][col] = now;
    return cnt + now;
}

class Solution {
public:
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        rows = grid.size();
        if( rows == 0 ) {
            return ans;
        }
        cols = grid[0].size();
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( grid[row][col] > 0 ) {
                    ans = max( ans, dfs( row, col, grid ) );
                }
            }
        }
        
        return ans;
    }
};
