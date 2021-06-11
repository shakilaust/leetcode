class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       
        sort( nums.begin(), nums.end());
        int ans = 0;
        for( int i = 0 ; i < nums.size() ; i++ ) {
            int k = i + 2; 
            for( int j = i + 1 ; j < nums.size() && nums[i] != 0 ; j++ ) {
                while( k < nums.size() && nums[i] + nums[j] > nums[k] ) {
                    k++;
                }
                ans += ( k - j - 1 );
            }
        }
        return ans;
    }
};
