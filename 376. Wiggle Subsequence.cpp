class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if( !n ) return 0;
        vector < vector < int > > dp( n + 1 , vector < int > ( 2 , 1 ) ); // 0 for pos, 1 for neg
        
        
        
        
     
        int ans = 1;
        
        for( int i = 0 ; i < n ; i++ ) { 
            
            for( int j = i + 1 ; j < n ; j++ ) { 

                if( nums[j] > nums[i] ) { 

                    dp[j][0] = max( dp[j][0] , dp[i][1] + 1 );
                } else if( nums[j] < nums[i] ){
                    dp[j][1] = max( dp[j][1] , dp[i][0] + 1 );
                }
                
                ans = max( ans , max( dp[j][0], dp[j][1] ) );
            }

        }
     
        return ans;
    }
};
