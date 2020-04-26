class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        int aSz = A.size();
        int bSz = B.size();
        vector < vector < int > > dp( aSz + 1 , vector < int > ( bSz + 1 , 0 ) );
        
        for( int i = 1 ; i <= aSz ; i++ ) { 

            for( int j = 1 ; j <= bSz ; j++ ) { 
                if(A[i-1] == B[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j]));
            }
        }
        
        return dp[aSz][bSz];
    }
};
