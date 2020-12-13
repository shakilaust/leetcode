
const int NX = 1005;

int dp[ NX ][ NX ];
int comSum[ NX ][ NX ];

int DP(  int x, int y ) {
    if( x >= y ) return 0;
    int &ret = dp[x][y];
    if( ret != -1 ) return ret;
    int a =  comSum[ x + 1 ][ y ] - DP( x + 1 , y );
    int b = comSum[x][y-1] - DP( x , y - 1 );
    ret = max( a, b );
    return ret;
}

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector < int > sum( n , 0 );
        if( n == 0 ) return 0;
        sum[0] = stones[0];
        for( int i = 1 ; i < n ; i++ ) {
            sum[i] = ( sum[i-1] + stones[i]);
        }
        
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = i ; j < n ; j++ ) {
                if( i == 0 ) comSum[i][j] = sum[j];
                else comSum[i][j] = ( sum[j] - sum[i-1] );
                dp[i][j] = -1;
            }
        }
        
       return DP( 0 , n - 1 );
    }
};
