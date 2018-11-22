class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3] = {0};
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            freq[nums[i]]++;
        }
        for( int i = 0, idx = 0 ; i < 3 ; i++ ) { 
            while( freq[i]-- ) {
                nums[idx++] = i;
            }
        }
        
    }
};
