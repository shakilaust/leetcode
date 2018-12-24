class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector < int > dp;
        for( int i = 0; i <= amount ; i++ ) dp.push_back(-1);
        dp[0] = 0;
        int sz = coins.size();
        for( int i = 0; i < sz ; i++ ) { 
            for( int j = coins[i]; j <= amount ; j++ ) { 
                if(dp[j-coins[i]] != -1 ) { 
                    if( dp[j] == -1 ) dp[j] = dp[j-coins[i]] + 1;
                    else dp[j] = min( dp[j] , dp[j-coins[i]] + 1);
                }
            }
        }
        return dp[amount];
    }
};
