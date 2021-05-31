class Solution {
public:

    bool checkPossibility(vector<int>& nums) {
       int notOk = 0;
        for( int i = 1; i < nums.size() ; i++ ) {
            if( nums[i-1] > nums[i] ) {
                if( notOk == 1 ) {
                    return false;
                }
                notOk++;
                if( i - 2 < 0 ||  nums[i-2] <= nums[i] ) {
                    nums[i-1] = nums[i];
                } else {
                    nums[i] = nums[i-1];
                }
            }
        }
        
        return true;
        
    }
};
