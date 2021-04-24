class Solution {
public:
    map < int , vector < int > > index;
    unordered_map < int, int > degree;
    Solution(vector<int>& nums) {
        for( int i = 0 ; i < nums.size() ; i++ ) {
            index[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if( index[target].size() == degree[target] ) {
            degree[target] = 0;
        }
        int ans = index[target][degree[target]];
        degree[target] = degree[target] + 1;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
