
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
       int ans = -1;
       for( int i = 1 ; i < nums.size() && ans < 0 ; i++ ) { 
            k -= ( nums[i] - nums[i-1] - 1);
            if( k <= 0 ) { 
               ans = ( nums[i] - ( abs(k) + 1 ) );
               
            }
       }
        
      if( ans < 0 ) { 
        return nums[nums.size() - 1 ] + k ;
      } else {
        return ans;
     }
    }
};
