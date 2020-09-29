class Solution {
public:
    int integerBreak(int n) {
        vector < int > dp( n + 1 );
        dp[1] = 1;
        dp[2] = 1;
        for( int i = 3 ; i <= n ; i++ ) { 
            dp[i] = 1;
            for( int j = 1 ; j <= i / 2 ; j++ ) { 

                int a = max( j * ( i - j ), dp[j] * dp[i - j ] );
                int b = max( dp[j] * ( i - j ) , dp[ i - j ] * j );
                dp[i] = max( dp[i], max( a, b ) );
                


            }
    
        }
        return dp[n];
    }
};
