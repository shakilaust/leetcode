class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        vector< int > possibleSorted;
        for( int i = 0 ; i < sz ; i++ ) { 
            possibleSorted.push_back(nums[i]);
        }

        sort(possibleSorted.begin(), possibleSorted.end());
        int lft = -1;
        for( int i = 0 ; i < sz ; i++  ) {
            if( possibleSorted[i] != nums[i]) {
                lft = i;
                break;
            }
        }

        if( lft == -1 ) // already sorted 
            return 0;
        
        int rgt = -1;
        for( int i = sz - 1 ; i >= 0 ; i-- ) {
            if( possibleSorted[i] != nums[i] ) {
                rgt = i;
                break;
            }
        
        }
        
        return ( rgt - lft ) + 1;
 
    }
};
