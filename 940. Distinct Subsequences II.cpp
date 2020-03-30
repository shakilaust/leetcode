const int mod  = 1e9 + 7;

class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.size();
        
        vector < int > lst( 26 , -1 );
        vector < long > dp( n + 1 , 0 );
        
        dp[0] = 1;
        for( int i = 0 ; i < n ; i++ ) {
            
            int x = S[i] - 'a';
            dp[ i + 1 ] = ( 2 * dp[i] )%mod;
            if( lst[x] >= 0 ) {
                dp[i + 1] -= dp[lst[x]];
                dp[ i + 1 ] += mod;
                
            }
            
            dp[ i + 1 ] %= mod;
            lst[x] = i;
            

        }
        
        dp[n]--;
        
        if(dp[n] < 0 ) dp[n] += mod;
        return dp[n];
    }
};
