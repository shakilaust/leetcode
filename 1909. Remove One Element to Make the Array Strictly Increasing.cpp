class Solution {
public:
    bool isPossible( int pos, int lst, int prvLst, bool canSkip, vector < int > &nums ) {
        if( nums.size() == pos ) return true;
        if( lst >= nums[pos] ) {
            if( canSkip ) {
                bool ok = false;
                
                if( nums[pos] > prvLst ) {
                    ok = ok || isPossible( pos + 1 , nums[pos], prvLst, false , nums );
                }
                ok = ok || isPossible( pos + 1 , lst , prvLst, false, nums );
                return ok;
            } 
            return false;
        }
        return isPossible( pos + 1 , nums[pos], lst, canSkip, nums );
    }
    bool canBeIncreasing(vector<int>& nums) {
        return isPossible( 0 , -1 , -1, true , nums );
    }
};
