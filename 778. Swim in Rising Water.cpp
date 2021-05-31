 const int MX = 50;
const int NX = MX * MX + MX;
const int dx[4] = {1, -1, 0, 0 };
const int dy[4] = {0, 0, 1, -1};
const int INF = 1e7;
class Solution {
public:
   
    int dp[ MX + 2][ MX + 2 ][ NX ];
    vector < vector < int > > inp;
    int n;

    
    bool isPossible( int x, int y, int v ) {
        if( x >= 0 && y >= 0 && x < n && y < n && v >= inp[x][y] ) {
            return true;
        }
        return false;
    }
    int DP( int row, int col, int t) {
        if( row == n - 1 && col == n - 1 ) {
            return t;
        }
        if( t > NX ) return INF;
        
        int &ret = dp[ row ][ col ][ t ];
        if( ret != -1 ) {
            return ret;
        }
        ret = DP( row, col, t + 1 );
        if( t >= inp[row][col] ) {
            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = row + dx[i];
                int ny = col + dy[i];
                if( isPossible( nx, ny , t ) ) {
                    ret = min( ret, DP( nx, ny, t ) );
                }
            }
        }
        return ret;
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        inp = grid;
        memset( dp, -1, sizeof(dp));
        n = grid.size();
        return DP( 0 , 0 , 0 );
    }
};
