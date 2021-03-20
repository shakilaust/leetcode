const int ADD = 50000 + 5;
int freq[ ADD + ADD ];

class Solution {
public:
  
    vector<int> sortArray(vector<int>& nums) {
        int sz = nums.size();
        vector< int > ans;
        if( sz == 0 ) return ans;
        int mx = nums[0];
        for( int i = 1 ; i < sz ; i++ ) {
            if( nums[i] > mx ) mx = nums[i];
        }

        for( int i = 0 ; i < sz ; i++ ) {
            int x = nums[i] + ADD;
            freq[ x ]++;
        }
        
        for( int i = 0 ; i <= mx + ADD ; i++ ) {
            while( freq[i] > 0 ) {
                ans.push_back(i - ADD);
                freq[i]--;
            }
        }
        return ans;
    }
};
