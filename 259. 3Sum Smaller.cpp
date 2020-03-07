class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int ans = 0;
        for( int i = 0 ; i < nums.size(); i++ ) { 

           int lookFor = target - nums[i];
           int low = i + 1;
           int high = nums.size() - 1;
           while( high > low ) { 
                
               if( nums[low] + nums[high] < lookFor ) { 
                    ans += ( high - low );
                    low++;
                } else {
                    high--;
                }

            }
        }
        return ans;
    }
};
