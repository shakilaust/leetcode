const int NX = 55;
const int mod = 1e9 + 7;

int dp[ NX ][ NX ][ NX ];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isOutside(int m, int n, int x, int y ) { 

    if( x >= 0 && x < m && y >= 0 && y < n ) return false;
    return true;
    
}

int DP( int m, int n, int x, int y, int left) { 

    if( isOutside( m, n, x, y )) return 1;
    if( left == 0 ) return 0;
    int &ret = dp[x][y][left];
    if( ret != -1 ) return ret;
    ret = 0;
    for( int i = 0 ; i < 4 ; i++ ) { 
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret += DP( m , n , nx, ny, left -1 );
        ret %= mod;
    }
    return ret;

}

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        for(int i = 0 ; i < m ; i++ ) { 
            for( int j =  0 ; j < n ; j++) { 
                for( int k = 0 ; k <= N ; k++ ) { 
                    dp[i][j][k] = -1;
                }
            }
        }
        return DP(m, n, i, j, N);
    }
};
