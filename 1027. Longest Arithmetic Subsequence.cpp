const int NX = 1005;

class Solution {
public:
  
    int prv[ NX ][ 505 ];
    int dp[ NX ][ 505 ];
    
    void maxSequence(vector< int> &A, int &ans) {
        for( int i = 1 ; i < A.size(); i++ ) {
               for( int j = i - 1 ; j >= 0 ; j-- ) {
                   int d = A[i] - A[j];
                   if( d < 0 ) continue;
                   if( dp[j][d] == 0 ) {
                       dp[i][d] = max(dp[i][d], 2);
                   } else {
                       dp[i][d] = max( dp[i][d], dp[j][d] + 1);
                   }
                   ans = max( ans, dp[i][d]);
               }
           }
    }
    int longestArithSeqLength(vector<int>& A) {
      
        
           int ans = 0;
           maxSequence( A, ans);
           for( int i = 0 ; i < A.size() ; i++ ) {
               A[i] *= -1;
           }
           memset( dp, 0, sizeof(dp));
           maxSequence( A, ans);
           return ans;
    }
};
