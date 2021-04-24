class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int greater = 0, lesser = 0;
        for( int i = 1 ; i < A.size() ; i++ ) {
            if( A[i] > A[i-1] ) {
                greater++;
            } else if( A[i] < A[i-1] ) {
                lesser++;
            } else {
                greater++;
                lesser++;
            }
        }
        
        return A.size() == greater + 1 || A.size() == lesser + 1;
    }
};
