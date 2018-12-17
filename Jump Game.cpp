class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int sz = nums.size();
        vector < bool > dp( sz , false);
        dp[0] = true;
        for( int i = 0, mx = 0 ; i < sz && !dp[sz-1] && dp[i] ; i++ ) {
            for( int j = mx ; j <= i + nums[i];  j++ ) {
                dp[j] = true;
            }
            mx = max( mx, i + nums[i] );
          // cout << " i " << i << " nums[i] " << nums[i] << " mx " << mx << endl;
        }

        return dp[sz-1];
        
    }
};
