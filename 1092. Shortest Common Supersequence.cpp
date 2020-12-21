class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int sz1 = str1.size();
        int sz2 = str2.size();
        vector < vector < int > > dp( sz1 + 1, vector < int > ( sz2 + 1 , 0 ) );
        
        
        for( int i = 1 ; i <= sz1 ; i++ ) {
            for( int j = 1 ; j <= sz2 ; j++ ) {
                if( str1[i-1] == str2[j - 1] ) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j-1], max( dp[i][j-1], dp[i-1][j]));
                }
            }
        }

        string ans = "";
        int row = sz1;
        int col = sz2;
        while( row > 0 && col > 0 ) {
            if( str1[row - 1] == str2[col - 1] ) {
                ans += str1[row - 1];
                row--;
                col--;
            } else {
                if( dp[row-1][col] >= dp[row][col-1] ) {
                    ans += str1[row - 1];
                    row--;
                } else {
                    ans += str2[col - 1];
                    col--;
                }
            }
        }
        
        while( row > 0 ) {
            ans += str1[row-1];
            row--;
        }
        
        while( col > 0 ) {
            ans += str2[col - 1];
            col--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
