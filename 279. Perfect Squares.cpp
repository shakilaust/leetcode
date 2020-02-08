class Solution {
public:
    int numSquares(int n) {
        vector < int > dp( n + 1 , 0 );
        for( int i = 1 ; i <= n ; i++ ) dp[i] = dp[i-1] + 1;
        
        for( int v = 2 ; v * v <= n ; v++ ) { 
            
            int cur = v * v;
            for( int j = cur; j <= n ; j++ ) { 
                dp[j] = min( dp[j], dp[j-cur] + 1 );
            }

        }

        return dp[n];
        
        
    }
};
