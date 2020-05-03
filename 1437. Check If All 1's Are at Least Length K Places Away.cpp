class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lst = -1e9;
        for( int i = 0 ; i < nums.size(); i++ ) { 
            
            if( nums[i] > 0 && i - lst - 1 < k) { 
                return false;
             }
            lst = nums[i] == 1 ? i : lst;
        }
        return true;
    }
};
