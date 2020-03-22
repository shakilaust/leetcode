class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if( sz <= 1 ) return sz;
        vector < int > dp( sz + 1, 1 );
        vector < int > counts( sz + 1 , 1 );
        
        int mx = 0, ans = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            
            mx = max(mx, dp[i]);
            for( int j = i + 1 ; j < sz ; j++ ) { 
                if( nums[j] > nums[i] ) { 
                    
                   if( dp[i] >= dp[j] ) { 

                        dp[j] = dp[i] + 1;
                        counts[j] = counts[i];
                    } else if( dp[i] + 1 == dp[j] ) { 

                        counts[j] += counts[i];
                    }
                    
                    mx = max( mx, dp[j] );

                }
            }
            
           
        }

        for(int i = 0 ; i < sz ; i++ ) { 
            if( dp[i] == mx ) ans += counts[i];

        }
        
        return ans;
        
      
    }
};
