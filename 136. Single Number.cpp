class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            ans ^= nums[i];
        }
        return ans;
    }
};
