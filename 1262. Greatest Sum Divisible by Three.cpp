class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       int dp[3] = {0};
        
       for( int num: nums ) {
          int tmp[3] = {0};
          for( int i = 0;  i < 3 ; i++ ) {
              tmp[i] = dp[i];
          }
          for( int i = 0 ; i < 3 ; i++ ) {
               dp[ ( tmp[i] + num ) % 3 ] = max( dp[ ( tmp[i]  +  num ) % 3 ], tmp[i] + num );
           }
       }
        
        return dp[0];
        
        
    }
};
