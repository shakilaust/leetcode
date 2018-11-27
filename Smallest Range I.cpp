class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int min = A[0];
        int mx = A[A.size() - 1 ];
        int diff = mx - min;
        int ans = max( 0 , diff - ( 2 * K ) );
        return ans;
        
    }
};
