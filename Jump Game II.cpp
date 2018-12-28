class Solution {
public:
    int jump(vector<int>& nums) {
        vector < int > dp;
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) dp.push_back(-1);
        dp[0] = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            for( int j = min( sz - 1, i + nums[i] ) ; j >= i + 1 ; j-- ) { 
                if( dp[j] == -1 ) dp[j] = dp[i] + 1;
                else if( dp[j] > dp[i] + 1 ) dp[j] = dp[i] + 1;
                else break;
            }
        }
        return dp[sz-1];
    }
};
