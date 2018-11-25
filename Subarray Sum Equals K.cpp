class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int  sum = 0, ans = 0;
        int sz = nums.size();
        map < int , int > res;
        res[0]++;
        for( int i = 0 ; i < sz ; i++ ) { 
            sum += nums[i];
            ans += res[sum-k];
            res[sum]++;
        }
        return ans;
        
    }
};
