class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector < int > hasPresent( n + 1 , 0 );
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) { 
            hasPresent[nums[i]] = 1;
            while(hasPresent[ans] == 1 ) ans++;
        }
        return ans;
    }
};
