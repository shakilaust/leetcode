class Solution {
public:
    int getMoneyAmount(int n) {
        
        
        vector < vector < int > > dp( n + 1 , vector < int > ( n + 1, 0 ) );
        
        for( int dis = 2 ; dis <= n ; dis++ ) { 
            for( int s = 1, e = dis ; e <= n ; s++ , e++ ) { 
                if( e - s == 1 ) dp[s][e] = s;
                 else { 
                    dp[s][e] = s + dp[s+1][e];
                    for( int mid = s + 1 ; mid < e ; mid++ ) { 
                        dp[s][e] = min(dp[s][e], mid + max(dp[s][mid-1], dp[mid+1][e]));
                    }

                }
           }

        }
        
        return dp[1][n];
    }
};
