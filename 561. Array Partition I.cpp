class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int answer = 0;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for( int i = 1 ; i < sz ; i += 2 ) answer += min( nums[i], nums[i-1] );
        return answer;
    }
};
