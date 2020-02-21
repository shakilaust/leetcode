
bool cmp( vector < int > a , vector < int > b ) { 

    if(a[1] == b[1] ) return a[0] < b[0];
    return a[1] < b[1];
}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        const int mx = INT_MAX - 100;
        vector < int > dp( T + 1 , mx );
       
        dp[0] = 0;
        
        int sz = clips.size();
        sort( clips.begin(), clips.end(), cmp );
        for( int i = 0 ; i < sz ; i++ ) { 
            int mn = INT_MAX;
            for( int j = clips[i][0] ; j <= min(T, clips[i][1]) ; j++ ) { 
                mn = min( mn, dp[j] );
            }
            
        
            if( clips[i][0] <= T && T <= clips[i][1] ) dp[T] = min( dp[T], mn + 1 );
            else if( clips[i][1] <= T ) 
            {
                dp[clips[i][1]] = min( dp[clips[i][1]] , mn + 1 );
            }
   
            
        }
        return dp[T] == (mx) ? -1 : dp[T];
    }
};
