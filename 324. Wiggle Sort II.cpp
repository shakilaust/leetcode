class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        if( sz == 1 ) return;
        map < int, int> freq;
        vector < int > ans( sz, 0 );
        for( int x: nums) {
            freq[x * -1]++;
        }

        int curIdx = 1;
        for( auto it: freq ) {
            int value = it.first * -1;
            int times = it.second;
            while( times-- ) {
                nums[curIdx] = value;
                curIdx += 2;
                if( curIdx >= sz ) curIdx = 0;
            }
        }
        
    }
};
