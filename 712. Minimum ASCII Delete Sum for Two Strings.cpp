class Solution {
public:
    int minimumDeleteSum(string A, string B) {
        
        int aSz = A.size();
        int bSz = B.size();
        vector < vector < int > > dp( aSz  + 1 , vector < int > ( bSz + 1, 0 ));
        
        for( int row = 1 ; row <= aSz ; row++ ) { 
            dp[row][0] = dp[row-1][0] + int(A[row-1]);
        }
        
        for( int column = 1 ; column <= bSz ; column++ ) { 
            dp[0][column] = dp[0][column-1] + int(B[column-1]);
        }
        
        for( int row = 1 ; row <= aSz ; row++ ) { 
            for( int column = 1 ; column <= bSz ; column++ ) { 

                if( A[row-1] == B[column-1] ) dp[row][column] = dp[row-1][column-1];
                else { 
                    dp[row][column] = min( dp[row-1][column] + int(A[row-1]) , dp[row][column-1] + int(B[column-1]));
                }
            }
        }

        return dp[aSz][bSz];
    }
};
