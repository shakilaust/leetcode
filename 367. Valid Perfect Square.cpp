class Solution {
public:
    bool isPerfectSquare(int num) {
       long low = 1, high = num;
        while( low <= high ) { 
            long mid = ( low + high ) / 2ll;
            long square = mid * mid;
            if( square == num ) return true;
            if( square > num ) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
