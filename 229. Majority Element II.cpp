class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map < int, int > cnt;
        vector < int > ans;
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            cnt[nums[i]]++;
            if(cnt[nums[i]] > ( sz / 3 ) ) { 
                ans.push_back(nums[i]);
                cnt[nums[i]] = -sz;
            }
        }
        return ans;
    }
};
