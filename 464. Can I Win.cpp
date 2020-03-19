

const int NX = 1 << 20 + 1;
const int MX = 300 + 1;

bool dp[ NX ][ MX ], vis[ NX ][ MX ];


bool dfs( int mask, int left, int mx ) { 

    if( left <= 0 ) return false;
    
    if( vis[mask][left] == true ) return dp[mask][left];
    vis[mask][left] = true;
    for( int i = 1 ; i <= mx ; i++ ) { 

        if(!(mask & ( 1 << ( i - 1 ) ) )) { 
            if( dfs( mask | ( 1 << ( i - 1 ) ), left - i , mx ) == false ) { 
                return dp[mask][left] = true;
            }
        }
    }
    return dp[mask][left] = false;
}

class Solution {
public:
    bool canIWin(int mx, int total) {
        
        if( total == 0 ) return true;
        if( (mx * ( mx + 1 ) / 2) < total ) return false;
        for( int i = 0 ; i < ( 1 << mx ) ; i++ ) { 
            for( int j = 0 ; j <= total ; j++ ) { 
                vis[i][j] = false;
            }
        }
        
        return dfs(0, total, mx );
    }
};
