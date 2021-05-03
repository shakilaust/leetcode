class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int val = 5;
        while( true ) {
            int add = n / val;
          
            if( add ) ans += add;
            else break;
             val *= 5;
        }
        return ans;
    }
};
