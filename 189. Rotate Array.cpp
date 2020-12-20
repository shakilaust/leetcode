class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector < int > preSave;
        for( int x: nums ) {
            preSave.push_back(x);
        }
       
        int n = nums.size();
        k = k % n;
        for( int i = 0 ; i < n ; i++ ) {
            nums[i] = preSave[ ( i - k + n ) % n ];
        }
        
       
    }
};
