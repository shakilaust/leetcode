class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        vector < int > dp( sz + 1 );
        dp[0] = nums[0];
        int ans = dp[0];
        
        for( int i = 1 ; i < sz ; i++ ) { 
            dp[i] = max( nums[i], dp[i-1] + nums[i] );
            ans = max( dp[i], ans );
        }
        return ans;
    }
};
