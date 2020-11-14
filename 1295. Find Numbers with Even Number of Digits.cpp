class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for( int item: nums ) {
            int digit = 0;
            if( item < 0 ) item *= -1;
            if( item < 10 ) continue;
            while( item > 0 ) {
                item /= 10;
                digit++;
            }
            
            ans += ( digit % 2 == 0 );
            
        }
        return ans;
    }
};
