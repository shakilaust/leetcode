bool cmp( vector < int > &a, vector < int > &b) { 
    if(a[1] == b[1] ) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int sz = pairs.size();
        vector < int > dp( sz , 1 );
        int ans = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            ans = max( ans, dp[i] );
            for( int j = i + 1 ; j < sz ; j++ ) {

                if( pairs[i][1] < pairs[j][0] ) { 
                    dp[j] = max(dp[j], dp[i] + 1 );
                    ans = max( dp[j], ans );
                }
            }
        }
        return ans;
    }
};
