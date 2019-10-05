class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        long long int dp[ sz + 1 ][ m + 1];
        dp[ 0 ][ 1 ] = nums[0];
        for( int i = 1 ; i < sz ; i++ ) { 
            dp[i][1] = dp[i-1][1] + nums[i];
        }

        
        for( int parts = 2 ; parts <= m ; parts++ ) { 

            for( int pos = parts - 1 ; pos < sz ; pos++ ) { 
                
                int f = 1;
                
                for( int prv = pos - 1 ; prv >= parts - 2 ; prv-- ) { 

                    if( f ) { 
                        dp[pos][parts] = max( dp[prv][parts-1] , ( dp[pos][1] - dp[prv][1] ) );
                    } else {
                        dp[pos][parts] = min( dp[pos][parts] , max( dp[prv][parts-1] , ( dp[pos][1] - dp[prv][1] ) ));
                    }
                    
                    f = 0;
                }

            }
        }
        
        return dp[sz-1][m];
        

    
    }
};
