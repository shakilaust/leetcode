class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 ) return 0;
        long low = 1, high = x, ans = 1;
        while( low <= high ) { 
            int mid = ( low + high ) / 2;
            if( mid <= x / mid ) { 
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};
