class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if( sz == 0 ) return 0;
        map < int, int > previousEncounter;
        int sum = 0, ans = 0;
        previousEncounter[0] = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            if( nums[i] == 1 ) sum += 1;
            else sum -=1;
            if( previousEncounter.find(sum) != previousEncounter.end()) { 
                ans = max( ans , i - previousEncounter[sum] + 1);
            } else previousEncounter[sum] = i + 1;
        }
        return ans;
    }
};
