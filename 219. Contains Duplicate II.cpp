class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map < int, int > pos;
       int sz = nums.size();
       for( int i = 0 ; i < sz ; i++ ) {
           if( pos.find(nums[i]) != pos.end() ) {
              if( i - pos[nums[i]] <= k ) return true;
           }
           
           pos[nums[i]] = i;
       }
       return false;
    }
};
