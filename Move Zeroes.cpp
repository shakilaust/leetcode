class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            if( nums[i] != 0 ) { 
                for( int j = i ; j > 0 ; j-- ) { 
                    if( nums[j-1] != 0 ) break;
                    swap( nums[j], nums[j-1]);
                }
            }
        }
    }
};
