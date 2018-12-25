class Solution {
public:
    int dp[21][2001], total, inp[21], target;
    int DP( int pos, int s) { 
        if( pos == total ) return s == target;
        if(dp[pos][s+1000] != -1 ) return dp[pos][s+1000];
        int ans = 0;
        ans = DP( pos + 1, s - inp[pos]);
        ans += DP( pos + 1, s + inp[pos]);
        return dp[pos][s+1000] = ans;
    
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        total = nums.size();
        for( int i = 0 ; i < total; i++ ) { 
            inp[i] = nums[i];
        }
        for( int i = 0 ; i < total; i++ ) { 
            for( int j = 0 ; j < 2001; j++ ) dp[i][j] = -1;
        }
        target = S;
        return DP(0, 0);
        
    }
};
