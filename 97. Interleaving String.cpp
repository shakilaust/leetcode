const int NX = 105;
string A, B, C;
int aSz, bSz, cSz;

bool visits[ NX ][ NX ][ NX + NX ];
bool dp[ NX ][ NX ][ NX + NX ];


bool DP( int a, int b, int c) {
    if( a == aSz && b == bSz && c == cSz ) return true;
  
    if( visits[a][b][c] ) return dp[a][b][c];
    visits[a][b][c] = true;
    bool found = false;
    if( a < aSz && A[a] == C[c] && found == false ) {
        found = DP( a + 1, b, c + 1 );
    }
    if( b < bSz && B[b] == C[c] && found == false ) {
        found = DP( a, b + 1, c + 1 );
    }
    return dp[a][b][c] = found;
}


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        A = s1;
        B = s2;
        C = s3;
        aSz = A.size();
        bSz = B.size();
        cSz = C.size();
        if( aSz + bSz != cSz ) return false;
        for( int a = 0 ; a <= aSz ; a++ ) {
            for( int b = 0 ; b <= bSz ; b++ ) {
                for( int c = 0 ; c <= cSz ; c++ ) {
                    visits[a][b][c] = false;
                }
            }
        }
        return DP( 0 , 0 , 0 );
    }
};
