
const int NX = 2005;
const int INF = 1e9;
bool isPlaindrome[ NX ][ NX ];
int dp[ NX ][ NX ];





class Solution {
public:
    int minCut(string s) {
        int sz = s.size();
        for( int i = 0 ; i <= sz ; i++ ) {
            for( int j = 0 ; j <= sz ; j++ ) {
                dp[i][j] = INF;
                isPlaindrome[i][j] = false;
            }
        }
        
        for( int i = 0 ; i < sz ; i++ ) {
            for( int x = i, y = i ; x >= 0 && y < sz && s[x] == s[y] ; x--, y++ ) {
                isPlaindrome[x][y] = true;
            }
            
            for( int x = i - 1, y = i ; x >= 0 && y < sz && s[x] == s[y] ; x--, y++ ) {
                isPlaindrome[x][y] = true;
            }
        }
        for( int y = 0 ; y < sz ; y++ ) {
            for(int  x = y ; x >= 0 ; x-- ) {
                if( isPlaindrome[x][y] ) dp[x][y] = 0;
                else {
                    int ret = INF;
                    for( int middle = x ; middle < y ; middle++ ) {
                            ret = min( ret, dp[x][middle] + dp[middle + 1][y] + 1 );
                    }
                    dp[x][y] = ret;
                }
            }
        }
        return dp[0][sz-1];
    }
};
