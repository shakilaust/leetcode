class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector < int > answer = { -1, -1 };
        int low = lower_bound(nums.begin(), nums.end(), target ) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target ) - nums.begin();
        int sz = nums.size();
        if( sz > 0 ) {
            
            if( high <= sz && nums[high - 1] == target ) {
                answer[0] = low;
                answer[1] = high - 1;
            } 
        }
        return answer;
    }
};
