class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map < int, int > Idx;
        int cnt = 1;
        for( int i = 0 ; i < A.size() ; i++ ) { 
            if( Idx.find(A[i]) == Idx.end() ) { 
                Idx[A[i]] = cnt++;
            }
        }
        
        int ans = -1;
        for( int i = 0 ; i < A.size() && ans == -1 ; i++ ) {

            if( Idx[A[i]] < 0 ) ans = A[i];
            else Idx[A[i]] *= -1;
        }
        return ans;
    }
};
