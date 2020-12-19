

class Solution {
public:
    int numDistinct(string s, string t) {
       int sSz = s.size();
       int tSz = t.size();
       vector < vector < long long int > > dp( sSz + 1, vector < long long int > ( tSz + 1 , 0 ) );
       for( int i = 0 ; i <= sSz ; i++ ) {
           dp[i][tSz] = 1;
       }
        
       for( int i = sSz - 1 ; i >= 0 ; i-- ) {
           for( int j = tSz - 1 ; j >= 0 ; j-- ) {
               dp[i][j] = dp[i + 1][j];
               if( s[i] == t[j] ) {
                   dp[i][j] += dp[i+1][j+1];
               }
           }
       }
       return dp[0][0];
        
    }
};
