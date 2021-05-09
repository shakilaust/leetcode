class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int lft = 0;
        for( int rgt = 0 ; rgt < nums.size() ; rgt++ ) {
            if( nums[rgt] == 0 ) k--;
            while( k < 0 ) {
                if( nums[lft] == 0 ) k++;
                lft++;
            }
            ans = max( ans, rgt - lft + 1);
        }
        return ans;
    }
};
