


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector < int > dp( 4, 0 );
        int n = stoneValue.size();
        for( int i = n - 1 ; i >= 0 ; i-- ) {
            dp[i % 4] = -1e9;
            int taken = 0;
            for( int k = 0 ; i + k < n && k < 3 ; k++ ) {
                taken += stoneValue[i + k];
                dp[ i % 4 ] = max( dp[ i % 4 ] , taken - dp[ (i + k + 1) % 4 ] );
            }
        }
        if( dp[0] > 0 ) return "Alice";
        else if( dp[0] < 0 ) return "Bob";
        return "Tie";
        
    }
};
