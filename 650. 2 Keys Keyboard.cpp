class Solution {
public:
    int minSteps(int n) {
        
        if( n == 1 ) return 0;
        vector < int > dp( n + 1 , 0 );
      
        for( int i = 1 ; i <= n ; i++ ) { 
           dp[i] = i;
            for( int j = 2 ; j * j <= i ; j++ ) { 
                if( i % j == 0 ) { 

                    dp[i] = min( dp[i] , dp[j] + i / j );
                    dp[i] = min(dp[i], dp[i/j] + j );
                } 
            }

        }
        
        return dp[n];
        
        
    }
};
