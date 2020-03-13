class Solution {
public:
    int maxA(int N) {
        vector < int > dp( N + 1 , 0 );
        dp[0] = 0;
        int buffer = 0;
        for( int i = 1;  i <= N ; i++ ) { 
            dp[i] = max( dp[i] , dp[i-1] + 1 );
            for( int j = i + 3 , k = 2 ; j <= N ; j++ , k++ ) { 

                dp[j] = max( dp[j] , dp[i] * k );
              // cout << " dp[i] " << dp[i] << " dp[j] " << dp[j] << " k " << k << " j " << j << endl;
            }
        }
        return dp[N];
    }
};
