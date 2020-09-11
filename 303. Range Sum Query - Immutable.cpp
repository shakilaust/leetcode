class NumArray {
public:
    vector < int > sum;
    NumArray(vector<int>& nums) {
        int sz = nums.size();
        
        for( int i = 1 ; i < sz ; i++ ) nums[i] += nums[i-1];
        sum = nums;
    }
    
    int sumRange(int i, int j) {
        int ans = i - 1 >= 0 ? sum[j] - sum[i-1] : sum[j];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
