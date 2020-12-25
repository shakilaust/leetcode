class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        vector < int > rgt( sz + 1 , 0 );
        for( int i = sz - 2 ; i >= 0 ; i-- ) {
            rgt[i] = nums[i+1] + rgt[i+1];
            
        }
        
        
        for( int i = 0 ; i < sz ; i++ ) {
            if( sum == rgt[i] ) return i;
            sum += nums[i];
        }
        return -1;
    }
};
