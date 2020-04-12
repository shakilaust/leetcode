class Solution {
public:
    bool isMatch(string s, string p) {
        int sSz = s.size();
        int pSz = p.size();
        vector < vector < bool > > dp( sSz + 1 , vector < bool > ( pSz + 1 , false ) );
        dp[sSz][pSz] = true;
        
        for( int i = sSz ; i >= 0 ; i-- ) { 
            
            for( int j = pSz - 1 ; j >= 0 ; j-- ) { 

                bool match = i < sSz && ( s[i] == p[j] || p[j] == '.' );
                if( j + 1 < pSz && p[ j + 1] == '*' ) { 
                    dp[i][j] = dp[i][j+2] || ( match && dp[i+1][j] );
                } else {
                    dp[i][j] = match && dp[i+1][j+1];
                }
            }
        }
        
        
        return dp[0][0];
    }
};
