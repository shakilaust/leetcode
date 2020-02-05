class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int mul = 1;
        int sz = nums.size();
        int low = 0, high = 0;
        while( high < sz ) { 

            mul = ( mul * nums[high]);
            if( mul < k ) { 
                ans += ( high - low + 1 );
            } else {
            
                while( mul >= k && low <= high ) {
                    mul = ( mul / nums[low] );
                    low++;
                }
                if( mul < k && low <= high ) ans += ( high - low + 1 );
            }
            high++;
            
           // printf("ans : %d high: %d mul: %d\n", ans, high, mul );
            

        }

        return ans;
        
    }
};
