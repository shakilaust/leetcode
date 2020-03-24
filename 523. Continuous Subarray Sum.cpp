class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map < int, int > lst;
        int sum = 0;
        lst[0] = -1;
        for( int i = 0; i < nums.size() ; i++ ) { 

            sum += nums[i];
            if( k != 0 ) { 
                sum %= k;
            }
            
            if( lst.find(sum) != lst.end() && i - lst[sum] > 1 ) return true;
            if( lst.find(sum) == lst.end() ) lst[sum] = i;
        }
        return false;
    }
};
