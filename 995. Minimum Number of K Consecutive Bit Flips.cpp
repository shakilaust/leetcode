class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue < int > q;
        int ans = 0;
        for( int i = 0; i < A.size() ; i++ ) {
            if( A[i] != q.size() % 2 == 0 ? 1 : 0 ) {
                ans++;
                q.push( i + K - 1 );
            }
            while( !q.empty() && q.front() <= i ) q.pop();
        }
        
        return q.empty() ? ans : -1;
    }
};
