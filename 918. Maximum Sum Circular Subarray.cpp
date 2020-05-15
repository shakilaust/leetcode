class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int curSum = 0;
        int mx = 0;
        int mxEndHere = 0;
        int sz = A.size();
        vector < int > left( sz , 0 );
        vector < int > right( sz , 0 );
        for( int i = 0 ; i < sz ; i++ ) {
            curSum += A[i];
            mxEndHere += A[i];
            if( i ) {
                mx = max( mx, max( A[i] , mxEndHere ));
            }
            else {
                mx = A[i];
            }
            
            if( mxEndHere < 0 ) {
                mxEndHere = 0;
            }
            
            if( i ) {
                left[i] = max(left[i-1], curSum );
            } else {
                left[i] = curSum;
            }
            
           
        }
        
        curSum = 0;
        for( int i = sz - 1 ; i >= 0 ; i-- ) { 
            curSum += A[i];
            if( i == sz -1 ) { 
                right[i] = curSum;
            } else {    
                right[i] = max(right[i+1], curSum );

            }
            if( i ) { 
                mx = max( mx, left[i-1] + right[i] );
            }
        }
        
        
        return mx;
    }
};
