class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int sz = arr.size();
        vector < vector < int > > dp( sz + 1 , vector < int > ( sz + 1,  0 ) );
        for( int len = 1 ; len <= sz ; len++ ) { 
            for( int i = 0, j = len - 1 ; j < sz ; j++, i++ ) { 

                if( len == 1 ) { 
                    dp[i][j] = 1;
                } else if ( len == 2 ) { 
                    if( arr[i] == arr[i+1] ) dp[i][j] = 1;
                    else dp[i][j] = 2;
                } else { 

                    dp[i][j] = 1 + dp[i+1][j];
                    if( arr[i] == arr[j] ) dp[i][j] = min( dp[i][j], dp[i+1][j-1] );
                    for( int k = i + 1 ; k < j ; k++ ) dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
        
        return dp[0][sz-1];
    }
};
