class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector < int > answer;
        int sz = nums.size();
        for( int i = 0 ; i < sz; i++ ) { 
            int lookFor = abs(nums[i]);
            if( nums[lookFor - 1 ] < 0 ) { 
                answer.push_back(lookFor);
            } else {
                nums[lookFor - 1 ] *= -1;
            }
        }
        return answer;
    }
};
