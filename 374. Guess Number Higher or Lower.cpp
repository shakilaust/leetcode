/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int low = 1, high = n;
        while( low <= high ) { 
            long long int mid = ( low + high ) / 2ll;
            int g = guess(mid);
            if( g == 0 ) return mid;
            else if( g < 0 ) { 
                high = mid - 1;
            } else low = mid + 1;

        }
        
        return n;
    }
};
