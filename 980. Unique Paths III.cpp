const int NX = 1005;
int desX, desY;
int dx[] = { 1, -1, 0, 0};
int dy[] = { 0 , 0 , 1, -1};
int rows, cols;
int dp[ NX ][ NX ];

bool ok( int x, int y) {
    if( x >= 0 && x < rows && y >= 0 && y < cols ) return true;
    return false;
}

int DP( int x, int y,int z, vector<vector<int>>& grid) {
    //cout << " x " << x << " y " << y << " z " << z << endl;
    if( x == desX && y == desY ) return z == 0;
    int ret = 0;
    for( int i = 0 ; i < 4 ; i++ ) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( ok( nx, ny) && grid[nx][ny] != -1 ) { 
            int nxtZ = z - (grid[nx][ny] == 0 );
            int prv = grid[nx][ny];
            grid[nx][ny] = -1;
            ret += DP( nx, ny, nxtZ, grid);
            grid[nx][ny] = prv;
            
            
        }
    }
    return ret;
}

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int scrX, scrY;
        int z = 0;
        for( int row = 0 ; row < rows ; row++ ){
            for( int col = 0 ; col < cols ; col++ ) {
                if( grid[row][col] == 1 ) {
                    scrX = row;
                    scrY = col;
                } else if( grid[row][col] == 2 ) {
                    desX = row;
                    desY = col;
                } else if( grid[row][col] == 0 ) {
                    z++;
                }
            }
        }
        grid[scrX][scrY] = -1;
        return DP( scrX, scrY, z,  grid );
        
        
    }
};
