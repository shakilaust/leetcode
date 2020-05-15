class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur = 0, ans = 0;
        for( int i = 0 ; i < nums.size() ; i++ ) { 
            if( i > 0 && nums[i] > nums[i-1] ) {
                cur++;
            } else {
                cur = 1;
            }
            ans = max( ans, cur );
        
        }
        return ans;
    }
};
