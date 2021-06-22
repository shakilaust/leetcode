class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int idx = nums.size() - 1;
        int foundIdx = -1;
        while( idx - 1 >= 0 && foundIdx == -1 ) {
            if( nums[idx-1] < nums[idx] ) {
                foundIdx = idx;
                for( int i = idx + 1 ; i < nums.size() ; i++ ) {
                    if( nums[idx-1] >= nums[i] ) {
                        break;
                    }
                    if( nums[i] <= nums[foundIdx] ) {
                        foundIdx = i;
                    }
                    
                }
                  swap( nums[idx-1] , nums[foundIdx]);
            sort( nums.begin() + idx, nums.end());
                
            }
            
          
            idx -= 1;
           
            
        }
        
        if( foundIdx == -1 ) {
            return -1;
        }
        
        long long v = stoll(nums);
        if( v > INT_MAX ) {
            return -1;
        }
        return v;
    }
};
