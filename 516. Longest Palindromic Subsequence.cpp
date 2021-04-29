class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse( t.begin(), t.end() );
        int sz = s.size();
        vector < vector < int > > dp( sz + 1, vector< int > (sz + 1, 0 ) );
        
        for( int i = 1 ; i <= sz ; i++ ) {
            for( int j = 1 ; j <= sz; j++ ) {
                if( s[i-1] == t[j-1] ) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max( dp[i-1][j-1], max( dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[sz][sz];
    }
};
