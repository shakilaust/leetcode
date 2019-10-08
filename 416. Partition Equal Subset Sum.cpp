class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) sum += nums[i];
        
        if( sum % 2 ) { 
            return false;
        }
        
        bool dp[ sum + 1 ] = {0};
        dp[0] = 1;
        
        for( int i = 0 ; i < sz ; i++ ) { 

            for( int j = sum ; j >= nums[i] ; j-- ) { 
                if( dp[ j - nums[i] ] == true) dp[ j ] = true;
            }
        }
        
        return dp[ sum / 2 ] ;
        
    }
};
