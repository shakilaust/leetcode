class Solution {
public:
    const int INF = 1e7;
    const int NX = 4005;
    int dp[ 4005 ][ 2 ], visit[ 4005][ 2 ];
    int taken[ 4005 ], A, B, X;
    
    int DP( int pos, int lstReverse ) {
        if( pos >= NX ) return INF;
        if( pos < 0 ) return INF;
        if( taken[pos]   ) return INF;
         taken[pos] = 1;
        if( pos == X ) return 0;
        int &ret = dp[pos][lstReverse];
        if( ret != -1 ) return ret;
        if( lstReverse ) ret = DP( pos + A , 0 ) + 1;
        else ret = min( DP( pos + A, 0 ), DP( pos - B, 1 )) + 1;
        taken[pos]  = 0;
        return ret;
        
        
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for( int i = 0 ; i < NX ; i++ ) {
            taken[i] = 0;
            for( int j = 0 ; j < 2 ; j++ ) {
                dp[i][j] = -1;
                 visit[i][j] = 0;
            }
        }
        int sz = forbidden.size();
        for( int i = 0 ; i < sz ; i++ ) {
            taken[forbidden[i]] = 1;
        }
        A = a;
        B = b;
        X = x;
        int ans = DP( 0 , 0 );
        if( ans >= INF ) ans = -1;
        return ans;
        
        
    }
};
