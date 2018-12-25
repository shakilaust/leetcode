class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int asz = A.size();
        int bsz = B.size();
        int csz = C.size();
        int dsz = D.size();
        map < int, int > valuePresentinAB;
        for(int i = 0 ; i < asz ; i++ ) { 
            for( int j = 0 ; j < bsz ; j++ ) valuePresentinAB[A[i] + B[j]]++;
        }
        int ans = 0;
        for( int i = 0 ; i < csz ; i++ ) { 
            for( int j = 0 ; j < dsz ; j++ ) { 
                int total = C[i] + D[j];
                int findOut = total * -1;
                ans += valuePresentinAB[findOut];
            }
        }
        return ans;
    }
};
