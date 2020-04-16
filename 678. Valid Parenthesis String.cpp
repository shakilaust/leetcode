
const int NX = 105;

bool dp[ NX ][ NX ], present[ NX ][ NX ];
int len;

bool DP(int pos, int open, string &str) { 
    
    if( open < 0 ) return false;
    if( pos == len ) return open == 0;
    if( present[pos][open] ) return dp[pos][open];
    present[pos][open] = true;
    bool &ret = dp[pos][open];
    if( str[pos] == ')' && open == 0 ) return ret = false;
    if( str[pos] == ')' ) ret = DP( pos + 1 , open - 1 , str );
    else if( str[pos] == '(') ret = DP( pos + 1 , open + 1 , str );
    else ret = DP( pos + 1 , open , str ) || DP( pos + 1 , open + 1 , str ) || DP( pos + 1 , open - 1 , str );
    return ret;
    
}


class Solution {
public:
    bool checkValidString(string s) {
        len = s.size();
        for( int i = 0 ; i <= len ; i++ ) { 
            for( int j = 0 ; j <= len ; j++ ) { 
                present[i][j] = false;
            }
        }
        return DP(0,0,s);
    }
};
