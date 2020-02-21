
const int NX = 1005;

int dp[ NX ][ NX ], memo[ NX ][ NX ];
string inp;
int DP( int x, int y) { 
    
    if( x >= y ) {
        return 0;
    }
    
    int &ret = dp[x][y];
    if( memo[x][y] ) return ret;
    memo[x][y] = 1;
    if( inp[x] == inp[y] ) return ret = DP( x + 1 , y - 1 );
    else {

        ret = 1 + DP( x + 1 , y );
        return ret = min( ret, DP( x , y - 1 ) + 1 );
    }



}

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        inp = s;
        int len = s.size();
        for( int i = 0 ; i < len ; i++ ) { 
            for( int j = 0 ; j < len ; j++ ) { 
                memo[i][j] = 0;
            }
        }
        return DP( 0 , len - 1 ) <= k;
    }
};
