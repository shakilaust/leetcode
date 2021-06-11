class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int F, int S) {
         
      for( int i = 1 ; i < A.size() ; i++ ) {
          A[i] += A[i-1];
      }
        
      int res = A[ F + S - 1];
      int fMax = A[ F - 1];
      int sMax = A[S - 1];
      for( int i = F + S ; i < A.size() ; i++ ) {
          fMax = max( fMax , A[i - S] - A[ i - F - S ] );
          sMax = max( sMax, A[ i - F ] - A[ i - S - F ] );
          
          res = max( res, max( fMax + A[i] - A[i - S] , sMax + A[i] - A[ i - F ] ) );
      }
        
        return res;

    }
};
