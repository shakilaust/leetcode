class Solution {
public:
    bool isMatch(string s, string p) {
        int sSz = s.size();
        int pSz = p.size();
        vector < vector < bool > > dp(pSz + 1 , vector < bool > ( sSz + 1  , false ) );
        dp[0][0] = true;
        
        for( int i = 1 ; i <= pSz ; i++ ) { 

            if( p[i-1] == '*' ) { 
                int j = 1;
                while(!dp[i-1][j-1] && j <= sSz ) j++;
                dp[i][j-1] = dp[i-1][j-1]; // any charecter match true
                while( j <= sSz ) dp[i][j++] = true;
                
            } else { 

                for( int j = 1 ; j <= sSz ; j++ ) { 

                    if( p[i-1] == '?' ||  p[i-1] == s[j-1] ) { 
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        
        
        return dp[pSz][sSz];
    }
};
