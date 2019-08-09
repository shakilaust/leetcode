class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int sz = nums.size();
        if( sz == 1 ) return 0;
        if( sz == 2 ) { 
            if( nums[0] > nums[1] ) return 0;
            else return 1;
        }
        int ans = 0, got = 0;
        for( int i = 1 ; i < sz - 1 ; i++ ) 
            if( nums[i] > nums[i-1] && nums[i] > nums[i+1] && got == 0) {
                got = 1;
                ans = i;
        }
        if( got == 0 ) {
            if(nums[0] > nums[sz-1] ) return 0;
            return sz - 1;
        }
        return ans;
    }
};
