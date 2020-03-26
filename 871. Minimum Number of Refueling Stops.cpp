class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        

        int sz = stations.size();
        vector < long long int > dp( sz + 1 , 0 );
        dp[0] = startFuel;
        
        for( int st = 0 ; st < sz ; st++ ) { 

            for( int now = st ; now >= 0 && dp[now] >= stations[st][0] ; now--) { 
                dp[ now + 1 ] = max( dp[ now + 1] , dp[now] + stations[st][1] );
            }
        }
        
        for( int i = 0 ; i <= sz ; i++ ) { 
            if( dp[i] >= target ) return i;
        }
        
        return -1;
    }
};
