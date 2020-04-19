class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if( nums.size() < 3 ) return false;
        vector < int > low;
        low.push_back( nums[0]);
        for( int i = 1 ; i < nums.size() ; i++ ) { 
            low.push_back( min( low[i-1], nums[i] ) );
        }
        
        int mx = nums[nums.size() - 1 ];
        
        for( int i = nums.size() - 2 ; i >= 1 ; i-- ) { 

            if( low[i-1] < nums[i] && nums[i] < mx ) return true;
            mx = max( mx, nums[i] );
        }
        
        return false;
    }
};
