class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        int pos[sz + 2] = {0};
        int ans = 1;
        for( int i = 0 ; i < sz ; i++ ) { 
            if( nums[i] > -1 && nums[i] == ans ) { 
                pos[nums[i]] = 1;
                while( ans <= sz && pos[ans] == 1 ) ans++;
            }
            
            if( nums[i] > -1 && nums[i] <= sz ) pos[nums[i]] = 1;
        }
        return ans;
    }
};
