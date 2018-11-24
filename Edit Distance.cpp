class Solution {
public:
    int minDistance(string word1, string word2) {
        
            int szWord1 = word1.size();
            int szWord2 = word2.size();
            int dp[szWord1+1][szWord2+1];
            for( int i = 0 ; i <= szWord1 ; i++ ) { 
                for( int j = 0 ; j <= szWord2 ; j++) {
                    if( i == 0 || j == 0 ) {
                        dp[i][j] = max( i , j );
                    } else {
                        if( word1[i-1] == word2[j-1] ) { 
                            dp[i][j] = dp[i-1][j-1];
                        } else {
                            dp[i][j] = min( dp[i-1][j-1] , min(dp[i-1][j], dp[i][j-1])) + 1;
                        }

                    }
                }
            }
            return dp[szWord1][szWord2];
        
    }
};
