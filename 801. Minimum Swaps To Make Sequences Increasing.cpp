
int makeArrayIncreaing(vector<int> &A, vector<int> &B) {
        int sz = A.size();
        vector < vector< int > > dp( sz , vector < int > ( 2 ) );
        dp[0][0] = 0;
        dp[0][1] = 1;
        
        for( int i = 1 ; i < sz ; i++ ) { 
            for( int init = 0 ; init < 2 ; init++ ) dp[i][init] = INT_MAX;
            if( A[i] > A[i-1] && B[i] > B[i-1] ) { 
                dp[i][0] = min( dp[i][0], dp[i-1][0] );  // no swap
                dp[i][1] = min(dp[i][1], dp[i-1][1] + 1); // both swap
            }
            if( B[i] > A[i-1] && A[i] > B[i-1] ) {
                dp[i][0] = min(dp[i][0], dp[i-1][1] ); // previous swap
                dp[i][1] = min( dp[i][1] , dp[i-1][0] + 1 ); // current swap
            }
        }
        
        return min(dp[sz-1][0], dp[sz-1][1] );

}

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        return makeArrayIncreaing(A, B);
    }
};
