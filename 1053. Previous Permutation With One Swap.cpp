class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int sz = A.size();
        int possibleStart = sz - 2;
        while( possibleStart >= 0 ) {
            if( A[possibleStart] > A[possibleStart + 1 ] ) {
                int possibleSwapEnd = possibleStart + 1;
                for( int i = possibleSwapEnd + 1 ; i < sz ; i++ ) {
                    if( A[i] >= A[possibleStart] ) break;
                    if( A[possibleSwapEnd] < A[i] ) {
                        possibleSwapEnd = i;
                    }
                }
                
                swap( A[possibleSwapEnd], A[possibleStart]);
                break;
            }
            possibleStart -= 1;
        }
        return A;
    }
};
