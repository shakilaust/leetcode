class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid, ans = nums[0];
        while( low <= high ) { 

            mid = ( low + high ) / 2;
            if( nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min( ans, nums[mid]);
                low += 1;
                high -= 1;
                
            }
            else if( nums[mid] <= nums[high] ) { // mid to high sorted
                ans = min( ans, nums[mid]);
                high = mid - 1;
            } else { 
                ans = min( ans, nums[low] );
                low = mid + 1;
            }
            
            
        }
        
        return ans;
        
    }
};
