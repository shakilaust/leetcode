class Solution {
public:
    int longestMountain(vector<int>& A) {
        int sz = A.size();
        vector < int > left(sz + 1, 0 );
        vector < int > rgt( sz + 1 , 0 );
        
        for( int i = 1 ; i < sz ; i++ ) {
            if( A[i] > A[i-1] ) left[i] =  ( left[i-1] + 1 );
        }
        
        for( int i = sz - 2 ; i >= 0 ; i-- ) { 
            if( A[i] > A[i+1] ) { 
                rgt[i] = ( rgt[i+1] + 1 );
            }
        }

        int ans = 0;
        for( int i = 0 ; i < sz ; i++ ) {
            if( left[i] > 0 && rgt[i] > 0 ) ans = max( ans, left[i] + rgt[i] + 1);
        }
        return ans;
    }
};
