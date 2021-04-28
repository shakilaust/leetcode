class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while( x > 0 && y > 0 ) {
            int a = x % 2;
            int b = y % 2;
            x /= 2;
            y /= 2;
            ans += ( a != b );
        }
        while( x > 0 ) { 
            if( x % 2 ) ans++;
            x/=2;
        }
        while( y > 0 ) {
            if( y % 2 )  ans++;
            y/=2;
        }
        return ans;
    }
};
