class Solution {
public:
    int findIndex(vector< int > &nums, int low, int high , int lookFor) { 
        
        if( low > high ) return -1;
        int mid = ( low + high ) / 2;
        if(nums[mid] == lookFor ) return mid;
        else if( nums[mid] <= nums[high] ) {
            // case 1 
            if(nums[mid] < lookFor && lookFor <= nums[high] ) {
                return findIndex(nums, mid + 1 , high , lookFor );
            } else {
                return findIndex(nums , low , mid - 1 , lookFor );
            }
        } else {
            
           if(lookFor < nums[mid] && lookFor >= nums[low] ) {
                return findIndex(nums, low, mid - 1 , lookFor );
            }  else {
                return findIndex(nums, mid + 1 , high , lookFor );

            }


     }
        
    }
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        return findIndex(nums, 0, sz - 1 , target );
    }
};
