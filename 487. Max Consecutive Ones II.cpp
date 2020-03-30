class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int low = 0, high = 0, alreadyFliped = 0, ans = 0;
        while( high < nums.size() ) { 
            if( nums[high] == 0 && alreadyFliped ) {
                while( low < high && nums[low] == 1 ) low++;
                if( low < high && nums[low] == 0 ) low++;

            } else if( nums[high] == 0 && !alreadyFliped ) {
                alreadyFliped = 1;
            }
            
            ans = max( ans, high - low + 1 );
            high++;
            
    
        }
        
        return ans;
    }
};
