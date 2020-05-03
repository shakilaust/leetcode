class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector < int > dp( sz + 1 , INT_MAX);
        dp[0] = -INT_MAX;
        
        int lis = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            int low = lower_bound( dp.begin(), dp.end() , nums[i]) - dp.begin();
            dp[low] = nums[i];
            lis = max( lis, low );
        }
       
        return lis;
    }
};
