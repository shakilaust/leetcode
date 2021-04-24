class Solution {
    public boolean isMonotonic(int[] A) {
        int greater = 0, lesser = 0;
        for( int i = 1 ; i < A.length ; i++ ) {
            if( A[i] > A[i-1] ) {
                greater++;
            } else if( A[i] < A[i-1] ) {
                lesser++;
            } else {
                greater++;
                lesser++;
            }
        }
        
        return greater + 1 == A.length || lesser + 1 == A.length;
    }
}
