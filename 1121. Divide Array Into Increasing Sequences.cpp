class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int groups = 1, cnt = 1;
        int n = nums.size();
        for( int i = 1 ; i < n ; i++ ) {
            cnt = nums[i] > nums[i-1] ? 1 : cnt + 1;
            groups = max(groups, cnt ); // as already sorted 
        }
        
        return n >= groups * K;
    }
};
