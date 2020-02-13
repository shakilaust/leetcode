class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int low = 0, high = 0, sz = nums.size();
        int ans = 0, sum = 0;
        while( high < sz ) { 
            sum += nums[high];
            while( sum >= s ) {
                int tmp = high - low + 1;
                if( ans == 0 || ans > tmp ) ans = tmp;
                sum -= nums[low++];
            }
            high++;
        }
        return ans;
    }
};
