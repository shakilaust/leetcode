class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int bits[32] = {0};
        int sz = nums.size();
        int same = 0;
        if( sz == 1 ) return 0;
        for( int i = 0 ; i < sz ; i++ ) {
          
            for( int j = 0 ; j < 32 ; j++ ) { 
                if( nums[i] & ( 1 << j ) ) { 
                    bits[j]++;
                }
            }
        }
        int ans = 0, mx = 0;
        for( int i = 0 ; i < 32 ; i++ ) { 
          
            ans +=  ( bits[i] * (sz - bits[i]));
        }

        return ans;
        
    }
};
