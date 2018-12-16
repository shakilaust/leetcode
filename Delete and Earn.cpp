class Solution {
public:

    
    int deleteAndEarn(vector<int>& nums) {
        int mx = 0, sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) {
            mx = max( mx, nums[i]);
        }
        
        vector < int > dp(mx + 5), freq(mx + 5);
        for( int i = 0 ; i < sz ; i++ ) {
            freq[nums[i]]++;
        }

        dp[0] = 0;
        for( int i = 1 ; i <= mx ; i++ )
        {
            if( freq[i] > 0 ) {
                dp[i] = max( dp[i-1] , freq[i] * i + ( i - 2 >= 0 ? dp[i-2] : 0 ) );
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[mx];
    }
};
