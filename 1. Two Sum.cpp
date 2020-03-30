class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map < int, int > m;
        for( int i = 0 ; i < nums.size() ; i++ ) {
        
            if( m[nums[i]] > 0 ) return { m[nums[i]] - 1 , i };
            m[target - nums[i]] = i + 1;

        }
        
        return {};
    }
};
