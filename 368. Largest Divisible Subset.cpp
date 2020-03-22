class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector < int > dp( sz , 1 );
        int ans = 0;
        for( int i = 0 ; i < sz ;i++ ) { 
            ans = max( ans, dp[i] );
            for( int j = i + 1 ; j < sz ;j++ ) { 
                if( nums[j] % nums[i] == 0 ) { 
                    dp[j] = max( dp[j] , dp[i] + 1 );
                    ans = max( ans, dp[j] );
                }
            }
        }
        vector < int > res( ans );
        int idx = ans - 1;
        for( int i = sz - 1 ; i >= 0 && ans > 0 ; i-- ) { 
            if( dp[i] == ans ) { 
                res[idx--] = nums[i];
                ans--;
            }
        }
        return res;
    }
};
