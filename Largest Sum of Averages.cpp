class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int sz = A.size();
        double dp[sz + 2 ][ sz + 2 ] = {0};
        int cumSum[ sz + 2 ] = {0};
        for( int i = 0 ; i < sz ; i++ ) { 
            cumSum[i] =( i - 1 >= 0 ? cumSum[i-1] : 0) + A[i];
            dp[i][1] = ( cumSum[i] / (double) ( i + 1 ) );
        }
        
        for( int i = 2 ; i <= K ; i++ ) { 
            for( int j = 0 ; j < sz ; j++ ) { 
                for( int l = j ; l > 0 ; l-- ) { 
                    double diffIndx = ( j - l + 1 );
                    double total = ( cumSum[j] - cumSum[l-1] );
                    dp[j][i] = max( dp[j][i] , dp[l-1][i-1] + ( total ) / diffIndx );
                }
            }
        
        }
        return dp[sz-1][K];
    }
};
