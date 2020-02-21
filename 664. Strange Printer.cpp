const int NX = 105;

int dp[ NX ][ NX ], memo[ NX ][ NX ];

string inp;


int DP( int x, int y) { 

    if( x > y ) return 0;
    else if( x == y ) return 1;
    int &ret = dp[x][y];
    if( memo[x][y] == 1 ) return ret;
    memo[x][y] = 1;
  
        ret = 1 + DP( x + 1 , y );
        for( int i = x + 1 ; i <= y ; i++ ) { 
            
            if( inp[x] == inp[i] ) { 
                ret = min( ret , DP( x , i - 1 ) + DP( i + 1 , y ) );
            }

        }
    
    return ret;
}


class Solution {
public:
    int strangePrinter(string s) {

        inp = "";
        int sz = s.size();
        if( sz == 0 ) return 0;
        inp += s[0];
        for( int i = 1 ; i < sz ; i++ ) { 
            if( s[i] != s[i-1] ) inp += s[i];
        }
        
        int len = inp.size();
        for( int i = 0 ; i < len ; i++ ) { 
            for( int j = 0 ; j < len ; j++ ) { 
                memo[i][j] = 0;
            }
        }
        return DP( 0 , len - 1 );
    }
};
