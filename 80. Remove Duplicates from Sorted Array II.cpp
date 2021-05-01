class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, cnt = 0;
        for( int i = 0 ; i < nums.size() ; i++ ) {
           if( i ) {
               if( nums[i] == nums[i-1] ) {
                   cnt++;
                  if( cnt <= 2 ) {
                       nums[idx++] = nums[i];
                   } 
               } else {
                   cnt = 1;
                   nums[idx++] = nums[i];
               }
              
           } else {
               cnt = 1;
               nums[idx++] = nums[i];
           }
        }
        return idx;
    }
};
