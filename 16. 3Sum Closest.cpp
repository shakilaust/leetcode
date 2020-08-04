class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 
        
            int low = i + 1;
            int high = sz - 1;
            while( low < high ) { 
                int sum = nums[low] + nums[i] + nums[high];
                if( abs(target - sum ) < abs( diff ) ) { 
                    diff = target - sum;
                }
                if( sum < target ) { 
                    low++;
                } else { 
                    high--;
                }
            }
        }
        
        return target - diff;
        
    }
};
