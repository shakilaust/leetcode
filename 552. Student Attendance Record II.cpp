const int NX = 1e5 + 10;
const int mod = 1e9 + 7;



int dp[ NX ][ 2 ][ 3 ], N;

int DP( int pos, int absentTaken, int consequtiveL ) { 

    if( pos == N ) return 1;
    int &ret = dp[ pos ][ absentTaken ][ consequtiveL ];
    if( ret != -1 ) return ret;
    ret = DP( pos + 1 , absentTaken , 0 );
    if( ret > mod ) ret -= mod;
    if( consequtiveL < 2 ) {
        ret += DP( pos + 1 , absentTaken, consequtiveL + 1 );
    }
    if( ret > mod ) { 
        ret -= mod;
    }
    
    if( absentTaken == 0 ) { 
        ret += DP( pos + 1 , 1 , 0 );
    }
    if( ret > mod ) { 
        ret -= mod;
    }
    
    return ret;

    
}

class Solution {
public:
    int checkRecord(int n) {
        N = n;
        for( int i = 0 ; i <= n ; i++ ) { 
            for( int j = 0 ; j < 2 ; j++ ) { 
                for( int k = 0 ; k < 3; k++ ) { 
                    dp[i][j][k] = -1;
                }
            }
        }
        return DP( 0 , 0, 0 );
    }
};
